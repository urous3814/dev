import math
from datetime import datetime
from tkinter import *
from tkinter import filedialog
import cryptography

import PIL.Image
import PIL.ImageTk
import cv2
import pymysql

db = pymysql.connect(
    host='127.0.0.1',
    port=3306,
    user='root',
    passwd='admin',
    db='study_db',
    charset='utf8'
)
# pymysql.cursors.DictCursor
cursor = db.cursor()

exp_name = None
exp_type = None
exp_dir = None
track_v = None


class App:
    def __init__(self, window2):
        self.cap = None
        frame1 = Frame(window2, bd=1)
        frame1.pack(fill="both", expand=True)
        frame2 = Frame(window2, relief="solid", bd=1)
        frame2.pack(fill="both", expand=True)
        frame3 = Frame(window2, bd=1)
        frame3.pack(expand=True)
        self.name_label = Label(frame2, text="실험 이름:")
        self.name_entry = Entry(frame2)
        self.time_label = Label(frame2, text="트래커 시간간격:")
        self.time_entry = Entry(frame2)
        self.use_video = BooleanVar()
        self.camera_check = Checkbutton(frame1, text='동영상 사용', variable=self.use_video)
        self.name_label.grid(row=0, column=0)
        self.name_entry.grid(row=0, column=1)
        self.time_label.grid(row=1, column=0)
        self.time_entry.grid(row=1, column=1)
        self.exp_dir = None
        self.frame = Frame(frame1)
        self.set = False
        self.tracker = None
        self.start_t = None
        self.canvas_move_y = None
        self.canvas_start_y = None
        self.canvas_start_x = None
        self.canvas_move_x = None
        self.standard_set = False
        self.photo = None
        self.ten_stand = 0
        self.db = db                          #360 400
        self.second = 0
        self.cursor = cursor
        self.exp_name = exp_name
        self.width, self.height = 320, 240
        self.window2 = window2
        self.window2.geometry("320x400")
        self.window2.title("Tracker Form")
        self.bg = 'white'
        self.canvas = Canvas(frame1, width=self.width, height=self.height)
        self.canvas.pack()
        self.canvas.bind("<Button-1>", self.mouse_down)
        self.canvas.bind("<B1-Motion>", self.mouse_move)
        self.canvas.bind("<ButtonRelease-1>", self.mouse_up)
        self.canvas_on_down = False
        self.tracking = False
        self.first_x = 10293847
        self.first_y = 10293847
        self.track_v = track_v
        self.v = 0.0
        self.x = 0.0
        self.y = 0.0
        self.d = 0.0

        self.Start_Button = Button(frame3, text="실험 시작", command=self.start_track)
        self.Start_Button.grid(row=0, column=0)
        self.Standard_Button = Button(frame3, text="기준 잡기", command=self.set_standard)
        self.Standard_Button.grid(row=0, column=1)
        self.Save_Button = Button(frame3, text="실험 저장", command=self.save_track)
        self.Save_Button.grid(row=0, column=2)
        self.ex_d = 0.0
        self.a = 0.0
        self.ex_v = 0.0
        self.seta = 0.0
        self.delay = 1
        self.camera_check.pack()
        self.now_t = datetime.now()
        self.window2.mainloop()

    def update(self):
        if self.set:
            ret, self.frame = self.cap.read()
            self.frame = cv2.cvtColor(self.frame, cv2.COLOR_BGR2RGB)
            if self.canvas_on_down:
                self.frame = cv2.rectangle(self.frame, (self.canvas_start_x, self.canvas_start_y),
                                           (self.canvas_move_x, self.canvas_move_y), (0, 0, 255), 2)
            if self.tracking:
                found, track_pos = self.tracker.update(self.frame)
                if found:
                    p1 = (int(track_pos[0]), int(track_pos[1]))
                    p2 = (int(track_pos[0] + track_pos[2]), int(track_pos[1] + track_pos[3]))
                    if self.first_x == 10293847:
                        self.first_x = (int(track_pos[0] + track_pos[2]) / 2)*10/self.ten_stand
                        self.first_y = (int(track_pos[1] + track_pos[3]) / 2)*10/self.ten_stand
                        self.ex_d = 0.0
                        self.ex_v = 0.0
                    cv2.rectangle(self.frame, p1, p2, (255, 0, 0), 2)
                    self.now_t = datetime.now() - self.start_t
                    if self.now_t.microseconds * 100000 >= self.second:
                        self.x = (int(track_pos[0] + track_pos[2]) / 2)*10/self.ten_stand
                        self.y = (int(track_pos[1] + track_pos[3]) / 2)*10/self.ten_stand
                        self.d = math.sqrt(pow(self.x - self.first_x, 2) + math.pow(self.y - self.first_y, 2))
                        self.v = (self.d - self.ex_d) / self.track_v
                        self.a = (self.v - self.ex_v) / self.track_v
                        self.seta = math.atan2(self.y - self.first_y,
                                               self.x - self.first_x) * 180 / 3.1415926535897932384
                        self.second = round(self.second + self.track_v, 1)
                        sql = "insert into experiment(Exp_Name, SECOND, Obj_X, Obj_Y, Obj_V, Obj_A, Obj_SETA) values " \
                              "(%s,%s,%s,%s,%s,%s,%s) "
                        self.cursor.execute(sql, (
                            self.exp_name, round(self.second, 1), int(track_pos[0] + track_pos[2]) / 2 - self.first_x,
                            int(track_pos[1] + track_pos[3]) / 2 - self.first_y, self.v, self.a, self.seta))
                        self.db.commit()
                    self.first_x = int(track_pos[0] + track_pos[2]) / 2
                    self.first_y = int(track_pos[1] + track_pos[3]) / 2
                    self.ex_d = self.d
                    self.ex_v = self.v
            self.photo = PIL.ImageTk.PhotoImage(image=PIL.Image.fromarray(self.frame))
            self.canvas.create_image(0, 0, image=self.photo, anchor=NW)
            self.window2.after(self.delay, self.update)

    def mouse_down(self, evt):
        self.canvas_on_down = True
        self.tracking = False
        self.second = 0
        self.first_x = 10293847
        self.canvas_start_x, self.canvas_start_y = int(evt.x), int(evt.y)
        self.canvas_move_x, self.canvas_move_y = int(evt.x), int(evt.y)

    def mouse_move(self, evt):
        self.canvas_move_x, self.canvas_move_y = int(evt.x), int(evt.y)

    def mouse_up(self, evt):
        self.start_t = datetime.now()
        self.canvas_on_down = False
        if self.standard_set:
            self.tracking = False
            a = (self.canvas_start_x, self.canvas_start_y)
            b = (self.canvas_move_x, self.canvas_move_y)
            self.ten_stand = math.dist(a, b)
            print(self.ten_stand)
            self.standard_set = False
        # self.tracker = cv2.TrackerKCF_create()  #빠르게
        else:
            self.tracking = True
            self.tracker = cv2.TrackerCSRT_create()  # 정확하게
            bbox = (min(self.canvas_start_x, self.canvas_move_x), min(self.canvas_start_y, self.canvas_move_y),
                    abs(self.canvas_move_x - self.canvas_start_x), abs(self.canvas_move_y - self.canvas_start_y))
            self.tracker.init(self.frame, bbox)

    def start_track(self):
        self.exp_name = self.name_entry.get()
        self.track_v = float(self.time_entry.get())
        if self.exp_name!= '' and self.track_v>0:
            if self.use_video.get():
                self.exp_dir = filedialog.askopenfilename(initialdir="/", title="Select file",
                                                          filetypes=(("Videos",
                                                                      "*.mkv *.avi *.mp4 *.mpg *.flv *.wmv *.asf *.asx *.ogm *.ogv *.mov"),
                                                                     ("all files", "*.*")))
            self.set = True
            print(self.exp_dir)
            if self.use_video.get():
                self.cap = cv2.VideoCapture(self.exp_dir)
                fps = self.cap.get(cv2.CAP_PROP_FPS)
                self.delay = round(1000 / fps)
            else:
                self.cap = cv2.VideoCapture(0)
            self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, self.width)
            self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, self.height)
            self.update()

    def set_standard(self):
        self.standard_set = True

    def save_track(self):
        self.canvas_on_down = True
        self.tracking = False
        self.name_entry.delete(0, 'end')
        self.time_entry.delete(0, 'end')
        self.exp_dir = ""
        self.cap = None
        self.set = False
        self.canvas.delete('all')
        self.second = 0
        self.first_x = 10293847


def doing_exp():
    App(Tk())


if __name__ == "__main__":
    App(Tk())
