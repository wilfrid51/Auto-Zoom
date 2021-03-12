#include "funcs.h"

int main() {
    try{
        system("taskkill /IM \"AutoJoinZoom.exe\" /F");
        print("AutoJoinZoom.exe has been killed.");
    } catch (int e) {
        std::cerr << "Error" << std::endl;
    }
    return 0;
}