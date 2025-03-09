#include <iostream>
#include <filesystem>
#include <vector>
#include <chrono>
#include <thread>
#include "includes/getterminalsize.h"
#include "includes/getcontentsofdir.h"
#include "includes/getselectedcharacter.h"
#include "includes/consVectorHandler.h"
#include "includes/keypresshandler.h"
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
            std::string interpreted = interpretKeys(ch);
            std::string userCommand;
            if (interpreted == "none") {
                std::cout << "Pressed key: " << ch << std::endl;
            } else if (interpreted == "q") {
                running = false;
            } else if (interpreted == "up") {
                consolevectorhandler::changeSelection(consolevectorhandler::getCurrentSelected() - 1, consolevectorhandler::getVectorLength());
            } else if (interpreted == "down") {
                consolevectorhandler::changeSelection(consolevectorhandler::getCurrentSelected() + 1, consolevectorhandler::getVectorLength());
            } else if (interpreted == ":") {
                consolevectorhandler::updateScreen();
                std::cout << ":";
                std::getline(std::cin, userCommand);
                if (userCommand == "exit") {
                    running = false;
                } else if (userCommand == "Ex") {
                    std::cout << "Directory: ";
                    std::getline(std::cin, filedirectory);
                    std::vector<std::string> filesindir = getContentsInDir(filedirectory);
                    consolevectorhandler::clearConsoleVector();
                    for (int i = filesindir.size(); i > 0; i--) {
                        consolevectorhandler::addToVector(filesindir[filesindir.size() - i]);
                    }
                    consolevectorhandler::updateScreen();
                }
            }
        }
        consolevectorhandler::updateScreen();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));  // Frame delay
    }
    return 0;
}
