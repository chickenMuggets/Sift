#include <iostream>
#include <filesystem>
#include <vector>
#include <chrono>
#include <thread>
#include "includes/getterminalsize.h"
#include "includes/getcontentsofdir.h"
#include "includes/getselectedcharacter.h"
#include "includes/consVectorHandler.h"
#ifdef _WIN32
#include <conio.h>
#endif

int main(int argc, char** argv) {
    std::string filedirectory;
    if (argc > 1) {
        filedirectory = argv[1];
    }
    else {
        #ifdef _WIN32
        filedirectory = "C:/";
        #else
        filedirectory = "/usr/";
        #endif   
    }
    std::vector<std::string> filesindir = getContentsInDir(filedirectory);
    bool running = true;
    while (running) {
        for (int i = filesindir.size(); i > 0; i--) {
            consolevectorhandler::addToVector(filesindir[filesindir.size() - i]);
        }
        consolevectorhandler::updateScreen();
        
        if (_kbhit) {
            char ch = getchrim();
            if (ch == 'q') {
                running = false;
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
    std::cout << "Press any key to continue...";
    std::cin.get();
    return 0;
}

bool sleep = true;
