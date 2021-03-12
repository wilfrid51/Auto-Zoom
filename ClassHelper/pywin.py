import pywinauto
import time
from pywinauto.keyboard import send_keys
import os

os.system("start cmd")
time.sleep(1)
try:
    app = pywinauto.application.Application().connect(title='C:\\Windows\\system32\\cmd.exe')

    win = app.window(title='C:\\Windows\\system32\\cmd.exe')
    if win.exists():
        print("win exists")
        time.sleep(2)
        win.type_keys("pssh {ENTER}")
        win = app.window(title='C:\\Windows\\system32\\cmd.exe - pssh')
        print("attempting to ssh into device")
        time.sleep(3)
        win.type_keys("samcoan10 {ENTER}")
        win = app.window(title='OpenSSH SSH client')
        time.sleep(3)
        win.type_keys("killall {SPACE} SpringBoard {ENTER}")
        print("springboard killed")
        time.sleep(10)
        win.close()
        print("win has been closed")
    else:
        print("win not found")
except pywinauto.findwindows.ElementNotFoundError:
    print("couldn't find the window, is it open?")