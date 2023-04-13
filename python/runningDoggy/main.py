from threading import Thread
import tkinter as tk
import os
from PIL import Image
import psutil
from multiprocessing import Queue

global i, plus
i = 5
plus = True

main_frame = tk.Tk()
im = Image.open("dDog.gif")
fim = Image.open("fDog.gif")
# print(ImageSequence.Iterator(im)[0].convert("RGB").g etpixel((800,600)))
running_dog = [tk.PhotoImage(file="dDog.gif", format="gif -index %i" %(i)) for i in range(im.n_frames)]
rrunning_dog = [tk.PhotoImage(file="fDog.gif", format="gif -index %i" %(i)) for i in range(im.n_frames)]


def update_window(cycle):
    global i, plus
    cycle = (cycle + 1) % len(running_dog)
    if(plus):
        if(i>=1800):
            plus = False
        i += 5
        frame = rrunning_dog[cycle]
    else:
        if(i<=0):
            plus = True
        i -= 5
        frame = running_dog[cycle]
    label.configure(image=frame)
    main_frame.after(30,update_window,cycle)
    main_frame.geometry('+'+str(i)+'+5')
    
    print(i)


label = tk.Label(main_frame,bd=0,bg='blue')
main_frame.overrideredirect(True)
main_frame.wm_attributes('-transparentcolor','blue')
main_frame.wm_attributes('-topmost',True)
main_frame.geometry("100x100+500+5")
label.pack()
main_frame.after(1,update_window,0)
main_frame.mainloop()
