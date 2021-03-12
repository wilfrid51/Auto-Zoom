#include <iostream> 
#include "funcs.h"
#include <filesystem>
#include <fstream>

int main() {
    print("AutoJoin Setup");
    bool ex = std::filesystem::exists("programdata.txt");
    if (ex == false) {
        std::ofstream txt("programdata.txt");
        txt.close();
    }
    input input;
    int classes = input.getclasses();
    input.classes = classes;
    return 0;
}