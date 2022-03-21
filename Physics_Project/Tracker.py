import cv2
import sqlite3
import PIL.Image, PIL.ImageTk
from tkinter import *
import pymysql 
from datetime import datetime

global db
db = pymysql.connect(
    host='127.0.0.1',
    port=3306,
    user='root',
    passwd='admin',
    db='study_db',
    charset='utf8'
)

global cursor
cursor = db.cursor(pymysql.cursors.DictCursor)

class App:
    def __init__(self, window):
        self.db = db
        self.second = 0
        self.cursor = cursor
        self.exp_name = exp_name

        self.width, self.height = 320,240
        self.window = window
        self.window.geometry("640x480")
        self.window.title("Tkinter + OpenCV")
        self.cap = cv2.VideoCapture(0)
        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, self.width)
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, self.height)
        self.canvas = Canvas(window, width = self.width, height = self.height)
        self.canvas.pack()
        self.canvas.bind("<Button-1>", self.mouse_down)
        self.canvas.bind("<B1-Motion>", self.mouse_move)
        self.canvas.bind("<ButtonRelease-1>", self.mouse_up)
        self.canvas_on_down = False
        self.tracking = False
        self.time = track_v
        self.first_x = 10293847
        self.first_y = 10293847
        self.track_v = track_v

        self.delay = 10
        self.update()
        self.window.mainloop()

    def update(self):
        ret, self.frame = self.cap.read()
        self.frame = cv2.cvtColor(self.frame, cv2.COLOR_BGR2RGB)
        if self.canvas_on_down == True:
            self.frame = cv2.rectangle(self.frame, (self.canvas_start_x, self.canvas_start_y), (self.canvas_move_x, self.canvas_move_y), (0, 0, 255), 2)
        
        if self.tracking == True:
            found, track_pos = self.tracker.update(self.frame)
            if found:
                p1 = (int(track_pos[0]), int(track_pos[1]))
                p2 = (int(track_pos[0] + track_pos[2]), int(track_pos[1] + track_pos[3]))
                if(self.first_x == 10293847):
                    self.first_x = int(track_pos[0] + track_pos[2])/2
                    self.first_y = int(track_pos[1] + track_pos[3])/2
                cv2.rectangle(self.frame, p1, p2, (255,0,0), 2)

                self.now_t = datetime.now() - self.start_t
                if(self.now_t.microseconds*100000 >= self.second):
                    print(self.second)
                    self.second+=self.track_v
                    sql = "insert into experiment(Exp_Name, SECOND, Obj_X, Obj_Y) values (%s,%s,%s,%s)"
                    self.cursor.execute(sql, (exp_name, self.second, int(track_pos[0] + track_pos[2])/2 - self.first_x, int(track_pos[1] + track_pos[3])/2 - self.first_y))
                    self.db.commit()

        self.photo = PIL.ImageTk.PhotoImage(image = PIL.Image.fromarray(self.frame))
        self.canvas.create_image(0, 0, image = self.photo, anchor = NW)
        self.window.after(self.delay, self.update)
    
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
        self.tracking = True
        #self.tracker = cv2.TrackerKCF_create()  #빠르게
        self.tracker = cv2.TrackerCSRT_create() #정확하게
        bbox = (min(self.canvas_start_x, self.canvas_move_x), min(self.canvas_start_y, self.canvas_move_y), abs(self.canvas_move_x - self.canvas_start_x), abs(self.canvas_move_y - self.canvas_start_y))
        self.tracker.init(self.frame, bbox)
global exp_name
exp_name = input("실험 이름 입력:")
track_v = float(input("트래커 시간간격 입력[초단위]:"))
App(Tk())
