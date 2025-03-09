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
    for (int i = filesindir.size(); i > 0; i--) {
        consolevectorhandler::addToVector(filesindir[filesindir.size() - i]);
    }
    bool running = true;
    std::cout << "\033[?25l";
    consolevectorhandler::updateScreen();
    while (running) {
        if (_kbhit) {
            int ch = getchrim();
            switch (ch)
            {
            case 113:  // 'q' to quit
                running = false;
                break;
            case -32:  // Arrow keys detection (ANSI escape code)
                ch = getchrim();
                if (ch == 72) {  // Up arrow key
                    consolevectorhandler::changeSelection(consolevectorhandler::getCurrentSelected() - 1);
                } else if (ch == 80) {  // Down arrow key
                    consolevectorhandler::changeSelection(consolevectorhandler::getCurrentSelected() + 1);
                }
                break;
            default:
                std::cout << "Pressed key: " << ch << std::endl;
                break;
            }
        }
        consolevectorhandler::updateScreen();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));  // Frame delay
    }
    return 0;
}
