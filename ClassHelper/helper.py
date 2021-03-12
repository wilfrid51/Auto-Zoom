import funcs as f
from datetime import datetime
import webbrowser
import json
import time
import pywinauto as win

now = datetime.now()
current_time = now.strftime("%H:%M")

with open("recources/data.json") as d:
    data = json.load(d)
    orig = data
    x = 0
    t = current_time.replace(":", "")
    while t <= "1525":
        while x <= data["classes"] - 1:
            if t >= data[f"{x + 1}"]["stime"] and t <= data[f"{x + 1}"]["etime"] and data[f"{x + 1}"]["joined"] == False:
                webbrowser.open(data[f"{x + 1}"]["link"])
                data[f"{x + 1}"]["joined"] = True
                with open("recources/data.json", "w") as w:
                    json.dump(data, w, indent=2)
                    w.close()
                if data[f"{x + 1}"]["name"] == "AP Spanish":
                    time.sleep(2)
                    app = win.application.Application().connect(title='Zoom')
                    w = app.window(title='Zoom')
                    w.type_keys("{ENTER}")
            x += 1
        time.sleep(3)
    with open("recources/data.json", "w") as w:
        json.dump(orig, w, indent=2)
        w.close()