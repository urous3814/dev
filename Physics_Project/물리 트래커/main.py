from tkinter import *
from tkinter.ttk import *
import Tracker as Trk


class MainApp:
    def refresh_click(self):
        self.dbgrid.delete(*self.dbgrid.get_children())
        sql = "select * from experiment "
        Trk.cursor.execute(sql)
        result = Trk.cursor.fetchall()
        i = 0
        for record in result:
            self.dbgrid.insert("", "end", text="", values=record, iid=i)
            i = i + 1

    def __init__(self, window):
        self.window = window
        self.window.geometry("640x480")
        self.window.title("Main Form")
        self.cursor = Trk.cursor
        self.dbgrid = Treeview(window,columns=['Exp_Name'])
        self.dbgrid.column('Exp_Name', anchor='center', width=150), self.dbgrid.heading('Exp_Name', text='실험 이름')
        # self.dbgrid.column('Obj_X', anchor='center', width=50), self.dbgrid.heading('Obj_X', text='x좌표')
        # self.dbgrid.column('Obj_Y', anchor='center', width=50), self.dbgrid.heading('Obj_Y', text='y좌표')
        # self.dbgrid.column('Obj_V', anchor='center', width=50), self.dbgrid.heading('Obj_V', text='속도')
        # self.dbgrid.column('Obj_A', anchor='center', width=50), self.dbgrid.heading('Obj_A', text='가속도')
        # self.dbgrid.column('Obj_SETA', anchor='center', width=50), self.dbgrid.heading('Obj_SETA', text='각도')
        # self.dbgrid.column('SECOND', anchor='center', width=100), self.dbgrid.heading('SECOND', text='시간')

        # columns = ['Exp_Name', 'Obj_X', 'Obj_Y', 'Obj_V', 'Obj_A', 'Obj_SETA', 'SECOND'],
        # displaycolumns = ['Exp_Name', 'Obj_X', 'Obj_Y', 'Obj_V', 'Obj_A', 'Obj_SETA', 'SECOND'])

        self.Button1 = Button(window, text="새로고침", command=self.refresh_click)

        self.dbgrid.grid(row=0, column=0)
        self.Button1.grid(row=0, column=1)
        self.window.mainloop()
        self.record = None
        self.result = None


MainApp(Tk())
