#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstring>
#include <filesystem>


void print(std::string str) {
    std::cout << str << std::endl;
}

void iprint(int x) {
    std::cout << x << std::endl;
}

std::vector<std::string> split(std::string str, char sep) {
    std::stringstream ss(str);
    std::string segment;
    std::vector<std::string> seglist;
    while(std::getline(ss, segment, sep)) {
        seglist.push_back(segment);
    }
    return seglist;
}


std::string getstr(std::string x = "") {
    std::cout << x;
    std::string in;
    std::getline(std::cin, in);
    return in;
}

int getint(std::string x = "") {
    std::cout << x;
    std::string in;
    std::getline(std::cin, in);
    int num = std::stoi(in);
    return num;
}

bool checkday(int x) {
    if(x == 0 || x == 3 || x == 6) {
        return true;
    } else {
        return false;
    }
}

void postwebhook() {
    system("curl -X POST -H \"Content-Type: application/json\" -d \"{\\\"username\\\": \\\"test\\\", \\\"content\\\":\\\"hello\\\"}\" https://discord.com/api/webhooks/809564212505870376/Ll-ukL5YJ4-z7k84M4XRI6gDV9lVLXmmirK_Fv5NaSwLRew-FeWpp2TdEVIIagDn3Y-J");
}

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

class timenow {
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

int errcheck() {
    std::fstream txt("programdata.txt");
    if(txt.peek() == std::ifstream::traits_type::eof()) {
        return 1;
    }
    txt.close();
    std::fstream txt2("programdata.txt");
    std::string classnum;
    std::string read;
    int linenum = 0;
    while(std::getline(txt2, read)) {
        linenum++;
        if(linenum == 1) {
            classnum = read;
        }
    }
    txt2.close();
    int classnumb = std::stoi(classnum);
    if((classnumb * 7) + 1 != linenum) {
        return 2;
    }
    return 0;
}

int classnum() {
    std::fstream txt2("programdata.txt");
    std::string classnum;
    std::string read;
    int linenum = 0;
    while(std::getline(txt2, read)) {
        linenum++;
        if(linenum == 1) {
            classnum = read;
            break;
        }
    }
    int classnumb = std::stoi(classnum);
    return classnumb;
}

classes getclassinfo(int x) {
    std::ifstream data("programdata.txt");
    std::string read;
    classes classes;
    if(x == 1) {
        for(int line = 1; std::getline(data, read) && line < 9; line++) {
            if(line == 4) {
                classes.name = read;
            } else if (line == 5) {
                classes.classlink = read;
            } else if(line == 6) {
                classes.extralink = read;
            } else if(line == 7) {
                classes.start = read;
            } else if(line == 8) {
                classes.end = read;
            }
            
        }
    }
    if(x == 2) {
        for(int line = 1; std::getline(data, read) && line < 16; line++) {
            if(line == 11) {
                classes.name = read;
            } else if (line == 12) {
                classes.classlink = read;
            } else if(line == 13) {
                classes.extralink = read;
            } else if(line == 14) {
                classes.start = read;
            } else if(line == 15) {
                classes.end = read;
            }
            
        }
    }
    if(x == 3) {
        for(int line = 1; std::getline(data, read) && line < 23; line++) {
            if(line == 18) {
                classes.name = read;
            } else if (line == 19) {
                classes.classlink = read;
            } else if(line == 20) {
                classes.extralink = read;
            } else if(line == 21) {
                classes.start = read;
            } else if(line == 22) {
                classes.end = read;
            }
            
        }
    }
    if(x == 4) {
        for(int line = 1; std::getline(data, read) && line < 30; line++) {
            if(line == 25) {
                classes.name = read;
            } else if (line == 26) {
                classes.classlink = read;
            } else if(line == 27) {
                classes.extralink = read;
            } else if(line == 28) {
                classes.start = read;
            } else if(line == 29) {
                classes.end = read;
            }
            
        }
    }
    std::vector<std::string> time = split(classes.start, ':');
    std::string h = time[0];
    int hour = std::stoi(h);
    classes.stime.hour = hour;
    std::vector<std::string> time2 = split(time[1], ' ');
    std::string m = time2[0];
    int min = std::stoi(m);
    classes.stime.min = min;
    if(time2[1] == "PM") {
        classes.stime.hour = 12 + hour;
    }
    time = split(classes.end, ':');
    h = time[0];
    hour = std::stoi(h);
    classes.etime.hour = hour;
    time2 = split(time[1], ' ');
    m = time2[0];
    min = std::stoi(m);
    classes.etime.min = min;
    if(time2[1] == "PM") {
        classes.etime.hour = 12 + hour;
    }
    return classes;
}

classes getlast() {
    int last = classnum();
    return getclassinfo(last);
}

void joinclass(std::string str, std::string extra = "") {
    char s[300];
    int i;
    for(i = 0; i <= str.length(); i++) {
        s[i] = str[i];
    }
    s[i+1] = '\0';
    char start[7] = "start ";
    char * const newstr = strcat(start, s);
    system(newstr);
    if(extra != "") {
        char s[300];
        int i;
        for(i = 0; i <= extra.length(); i++) {
            s[i] = extra[i];
        }
        s[i+1] = '\0';
        char start[7] = "start ";
        char * const newstr = strcat(start, s);
        system(newstr);
    }
}