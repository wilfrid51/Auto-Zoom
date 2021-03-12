#include <iostream>
#include "funcs.h"
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include "recources.h"
#include <filesystem>

#pragma comment(linker, "/SUBSYSTEM:WINDOWS")

using namespace std;

int main() {
    print("working");
    bool ex = std::filesystem::exists("programdata.txt");
    cout << ex << endl;
    print("working 2");
    if(ex == false) {
        print("working 3");
        std::ofstream txt("programdata.txt");
        txt.close();
        system("setup.exe");
        print("should have opened setup");
        return 0;
    }
    ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false);
    classes first;
    classes second;
    classes third;
    classes fourth;
    int err = errcheck();
    if(err != 0) {
        if(err == 1) {
            print("ERROR: PROGRAMDATA.TXT IS EMPTY");
            system("setup.exe");
            return 0;
        } else if(err == 2) { 
            print("ERROR: PROGRAMDATA.TXT IS MISSING INFORMATION. IT MAY HAVE BEEN EDITED INCORRECTLY OR IT MAY HAVE BEEN CORRUPTED.");
            system("setup.exe");
            return 0;
        }
    }
    int num = classnum();
    for(int x = 0; x <= num; x++) {
        if(x == 1) {
            first = getclassinfo(x);
        } else if(x == 2) {
            second = getclassinfo(x);
        } else if(x == 3) {
            third = getclassinfo(x); 
        } else if(x == 4) {
            fourth = getclassinfo(x);
        }
    }
    timenow tn;
    while(tn.hour() <= fourth.etime.hour && first.joined == false) {
        if(tn.hour() == first.stime.hour) {
            if(tn.minute() >= first.stime.min) {
                if(first.extralink != "null") {
                    joinclass(first.classlink, first.extralink);
                } else {
                    joinclass(first.classlink);
                }
                first.joined = true;
            }
        } else if(tn.hour() == second.stime.hour && second.joined == false) {
            if(tn.minute() >= second.stime.min) {
                if(second.extralink != "null") {
                    joinclass(second.classlink, second.extralink);
                } else {
                    joinclass(second.classlink);
                }
                second.joined = true;
            }
        } else if(tn.hour() == third.stime.hour && third.joined == false) {
            if(tn.minute() >= third.stime.min) {
                if(third.extralink != "null") {
                    joinclass(third.classlink, third.extralink); 
                } else {
                    joinclass(third.classlink);
                }
                third.joined = true;
            }
        } else if(tn.hour() == fourth.stime.hour && fourth.joined == false) {
            if(tn.minute() >= fourth.stime.min) {
                if(fourth.extralink != "null") {
                    joinclass(fourth.classlink, fourth.extralink);
                } else {
                    joinclass(fourth.classlink);
                }
                fourth.joined = true;
            }
        }
        Sleep(100);
    }
    return 0;
}