#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <fstream>

#ifndef FUNCS_H
#define FUNCS_H


void print(std::string);
void iprint(int);
std::vector<std::string> split(std::string, char);
std::string getstr(std::string);
int getint(std::string);
bool checkday(int);
void postwebhook();

class classes {
    public:
        std::string name;
        std::string classlink;
        std::string extralink;
        std::string start;
        std::string end;
        bool joined = false;
        struct stime {
            int hour;
            int min;
            std::string ampm;
        };
        struct stime stime;
        struct etime {
            int hour;
            int min;
            std::string ampm;
        };
        struct etime etime;
};

int errcheck();
int classnum();
classes getclassinfo(int); 

class timenow {
    public:
        int hour() {
            time_t now = time(0);
            tm * time = localtime(&now);
            int hour = time->tm_hour;
            return hour;
        }

        int minute() {
            time_t now = time(0);
            tm * time = localtime(&now);
            int min = time->tm_min;
            return min;
        }

        int day() {
            time_t now = time(0);
            tm * time = localtime(&now);
            int day = time->tm_wday;
            return day;
        }
};

class input {
    public:
        int classes;
        int getclasses() {
            while(true) {
                int num = getint("Number of classes:  ");
                if(num != 4) {
                    print("Sorry, the only amount of classes currently supported is 4!");
                } else {
                    classes = num;
                    std::ofstream txt("programdata.txt");
                    txt << num << std::endl;
                    return num;
                }
            }
        }
        std::string getclassname(int x) {
            
            //4 + (x * 7) - 4 = line to write to
        }
    

};

void joinclass(std::string, std::string="");

#endif