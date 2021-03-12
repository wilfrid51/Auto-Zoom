#include "funcs.h"
#include <iostream>
#include <ctime>
#include <Windows.h>

#pragma comment(linker, "/SUBSYSTEM:WINDOWS")

int main() {
    ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false);
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int day = ltm->tm_wday;
    std::cout << day << std::endl;

    if(checkday(day) == 1) {
        return 0;
    }

    int hour;
    int minute;
    time_t timenow1 = time(0);
    tm * time1 = localtime(&timenow1);
    hour = time1->tm_hour;
    minute = time1->tm_min;
    bool m1 = false;
    bool m2 = false;
    bool m3 = false;
    bool m4 = false;
    if(hour >= 10) {
        m1 = true;
        print("First class already over.");
    }
    if(hour >= 11) {
        m2 = true;
        print("Second class already over.");
    }
    if(hour > 13) {
        m3 = true;
        print("Third class already over.");
    }
    if(hour >= 15) {
        m4 = true;
        print("School day is over.");
    }
    std::cout << hour << std::endl;
    while((hour <= 15) || m4 == false) {
        time_t timenow = time(0);
        tm * time = localtime(&timenow);
        hour = time->tm_hour;
        minute = time->tm_min;
        if(hour >= 8 && m1 == false) {
            if(hour == 8) {
                if(minute >= 50) {
                    system("start https://classroom.google.com/u/1/w/ODcwMjQwNzExMzFa/t/all");
                    system("start https://translate.google.com/?sl=es&tl=en&op=translate");
                    system("start https://atlantapublicschools-us.zoom.us/j/82178284245?pwd=L1JSY016TFkxTTFuRFgvTW1UUVlLZz09");
                    print("Joined first class");
                    m1 = true;
                    system("curl -X POST -H \"Content-Type: application/json\" -d \"{\\\"username\\\": \\\"test\\\", \\\"Kaneki\\\":\\\"AutoJoinZoom.exe has joined your first class!\\\"}\" https://discord.com/api/webhooks/809564212505870376/Ll-ukL5YJ4-z7k84M4XRI6gDV9lVLXmmirK_Fv5NaSwLRew-FeWpp2TdEVIIagDn3Y-J");
                }
            } else {
                system("start https://classroom.google.com/u/1/w/ODcwMjQwNzExMzFa/t/all");
                system("start https://translate.google.com/?sl=es&tl=en&op=translate");
                system("start https://atlantapublicschools-us.zoom.us/j/82178284245?pwd=L1JSY016TFkxTTFuRFgvTW1UUVlLZz09");
                print("Joined first class");
                m1 = true;
                system("curl -X POST -H \"Content-Type: application/json\" -d \"{\\\"username\\\": \\\"Kaneki\\\", \\\"content\\\":\\\"AutoJoinZoom.exe has joined your first class!\\\"}\" https://discord.com/api/webhooks/809564212505870376/Ll-ukL5YJ4-z7k84M4XRI6gDV9lVLXmmirK_Fv5NaSwLRew-FeWpp2TdEVIIagDn3Y-J");
            }
        }
        if(hour >= 10 && m2 == false) {
            if(hour == 10) {
                if(minute >= 20) {
                    system("start https://classroom.google.com/u/1/w/MjIwODE2MTQ2NjE0/t/all");
                    system("start https://atlantapublicschools-us.zoom.us/j/82953306789?pwd=UVNBanU0SmNIQ094cmxZQjJEWnVOdz09");
                    print("Joined second class");
                    m2 = true;
                    system("curl -X POST -H \"Content-Type: application/json\" -d \"{\\\"username\\\": \\\"Kaneki\\\", \\\"content\\\":\\\"AutoJoinZoom.exe has joined your second class!\\\"}\" https://discord.com/api/webhooks/809564212505870376/Ll-ukL5YJ4-z7k84M4XRI6gDV9lVLXmmirK_Fv5NaSwLRew-FeWpp2TdEVIIagDn3Y-J");
                }
            } else {
                system("start https://classroom.google.com/u/1/w/MjIwODE2MTQ2NjE0/t/all");
                system("start https://atlantapublicschools-us.zoom.us/j/82953306789?pwd=UVNBanU0SmNIQ094cmxZQjJEWnVOdz09");
                print("Joined second class");
                m2 = true;
                system("curl -X POST -H \"Content-Type: application/json\" -d \"{\\\"username\\\": \\\"Kaneki\\\", \\\"content\\\":\\\"AutoJoinZoom.exe has joined your second class!\\\"}\" https://discord.com/api/webhooks/809564212505870376/Ll-ukL5YJ4-z7k84M4XRI6gDV9lVLXmmirK_Fv5NaSwLRew-FeWpp2TdEVIIagDn3Y-J");
            }
        }
        if(hour >= 12 && m3 == false) {
            if(hour == 12) {
                if(minute >= 40) {
                    system("start https://classroom.google.com/u/1/w/MjIwODgxOTU1Nzg1/t/all");
                    system("start https://atlantapublicschools-us.zoom.us/j/84469482800?pwd=WTBmT2psMjVxSVBlaVRWOFQ4aURTdz09");
                    print("Joined third class");
                    m3 = true;
                    system("curl -X POST -H \"Content-Type: application/json\" -d \"{\\\"username\\\": \\\"Kaneki\\\", \\\"content\\\":\\\"AutoJoinZoom.exe has joined your third class!\\\"}\" https://discord.com/api/webhooks/809564212505870376/Ll-ukL5YJ4-z7k84M4XRI6gDV9lVLXmmirK_Fv5NaSwLRew-FeWpp2TdEVIIagDn3Y-J");
                }
            } else {
                system("start https://classroom.google.com/u/1/w/MjIwODgxOTU1Nzg1/t/all");
                system("start https://atlantapublicschools-us.zoom.us/j/84469482800?pwd=WTBmT2psMjVxSVBlaVRWOFQ4aURTdz09");
                print("Joined third class");
                m3 = true;
                system("curl -X POST -H \"Content-Type: application/json\" -d \"{\\\"username\\\": \\\"Kaneki\\\", \\\"content\\\":\\\"AutoJoinZoom.exe has joined your third class!\\\"}\" https://discord.com/api/webhooks/809564212505870376/Ll-ukL5YJ4-z7k84M4XRI6gDV9lVLXmmirK_Fv5NaSwLRew-FeWpp2TdEVIIagDn3Y-J");
            }
        }
        if(hour >= 14 && m4 == false) {
            if(hour == 14) {
                if(minute >= 8) {
                    system("start https://classroom.google.com/u/1/w/MjQ5OTgzODc4OTQx/t/all");
                    system("start https://tinyurl.com/y3e7ul6j");
                    print("Joined fourth class");
                    m4 = true;
                    system("curl -X POST -H \"Content-Type: application/json\" -d \"{\\\"username\\\": \\\"Kaneki\\\", \\\"content\\\":\\\"AutoJoinZoom.exe has joined your fourth class!\\\"}\" https://discord.com/api/webhooks/809564212505870376/Ll-ukL5YJ4-z7k84M4XRI6gDV9lVLXmmirK_Fv5NaSwLRew-FeWpp2TdEVIIagDn3Y-J");
                }
            } else {
                system("start https://classroom.google.com/u/1/w/MjQ5OTgzODc4OTQx/t/all");
                system("start https://tinyurl.com/y3e7ul6j");
                print("Joined fourth class");
                m4 = true;
                system("curl -X POST -H \"Content-Type: application/json\" -d \"{\\\"username\\\": \\\"Kaneki\\\", \\\"content\\\":\\\"AutoJoinZoom.exe has joined your fourth class!\\\"}\" https://discord.com/api/webhooks/809564212505870376/Ll-ukL5YJ4-z7k84M4XRI6gDV9lVLXmmirK_Fv5NaSwLRew-FeWpp2TdEVIIagDn3Y-J");

            }
        }
        Sleep(1);
    }
    return 0;
}