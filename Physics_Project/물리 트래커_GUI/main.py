
import sys
from PyQt5.QtWidgets import *
from PyQt5 import uic

form_class = uic.loadUiType('MainForm.ui')[0]


class MyWindow(QMainWindow, form_class):
    def refresh_click(self):
        self.DBTable.clear
        sql = "select * from experiment "
        Trk.cursor.execute(sql)
        result = Trk.cursor.fetchall()
        i = 0
        for record in result:
            self.dbgrid.insert("", "end", text="", values=record, iid=i)
            i = i + 1

    def search(self, event):
        self.dbgrid.delete(*self.dbgrid.get_children())
        sql = "select * from experiment where Exp_Name = '" + self.combobox.get() + "' order by SECOND"
        print("select * from experiment where Exp_Name = '" + self.combobox.get() + "' order by SECOND")
        Trk.cursor.execute(sql)
        result = Trk.cursor.fetchall()
        i = 0
        for record in result:
            self.dbgrid.insert("", "end", text="", values=record, iid=i)
            i = i + 1

    def search_click(self):
        print("select")
        sql = "select distinct Exp_Name from experiment"
        Trk.cursor.execute(sql)
        result = Trk.cursor.fetchall()
        self.values = []
        for record in result:
            self.values.append(record)
        print(self.values)
        self.combobox['value'] = self.values

    @staticmethod
    def experiment_click():
        Trk.App(Toplevel())

    def __init__(self):
        super().__init__()
        self.setupUi(self)


if __name__ == '__main__':
    app = QApplication(sys.argv)
    MyWindow = MyWindow()
    MyWindow.show()
    app.exec_()
