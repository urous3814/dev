from threading import Thread
import tkinter as tk
import os
from PIL import Image
import psutil
from multiprocessing import Queue


main_frame = tk.Tk()
im = Image.open("dDog.gif")
# print(ImageSequence.Iterator(im)[0].convert("RGB").getpixel((800,600)))
running_dog = [tk.PhotoImage(file="dDog.gif", format="gif -index %i" %(i)) for i in range(im.n_frames)]

def update_window(cycle):
    frame = running_dog[cycle]
    cycle = (cycle + 1) % len(running_dog)
    label.configure(image=frame)
    main_frame.after(45,update_window,cycle)


label = tk.Label(main_frame,bd=0,bg='blue')
main_frame.overrideredirect(True)
main_frame.wm_attributes('-transparentcolor','blue')
main_frame.wm_attributes('-topmost',True)
main_frame.geometry("100x100+5+5")
label.pack()
main_frame.after(1,update_window,0)
main_frame.mainloop()
