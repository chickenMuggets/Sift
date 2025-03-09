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
#include "includes/logger.h"


int main(int argc, char** argv) {
    std::string filedirectory;
    if (argc > 1) {
        filedirectory = argv[1];
    }
    else {
        #ifdef _WIN32
        filedirectory = "C:";
        #else
        filedirectory = "/home/";
        #endif
    }

    std::vector<std::string> filesindir = getContentsInDir(filedirectory);
    int terminalSize = getTerminalSize(0);
    for (int i = 0; i < terminalSize && i < filesindir.size(); i++) {
        consolevectorhandler::addToVector(filesindir[i]);
    }
    

    bool running = true;
    std::cout << "\033[?25l";  // Hide cursor
    consolevectorhandler::updateScreen();

    while (running) {
        if (kbhit()) {
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
            } else if (interpreted == "enter") {
                std::string previousFileDirectory = filedirectory;
                log("the previous file directory is: " + previousFileDirectory);
                try {
                    filedirectory = filedirectory + "/"+ consolevectorhandler::getSelectedFile();
                    
                    if (std::filesystem::is_directory(filedirectory)) {
                        consolevectorhandler::changeSelection(0, consolevectorhandler::getVectorLength());
                        consolevectorhandler::updateScreen();
                        log("Changed directory to: " + filedirectory);
                        std::vector<std::string> filesindir = getContentsInDir(filedirectory);
                        consolevectorhandler::clearConsoleVector();
                        int terminalSize = getTerminalSize(0);
                        for (int i = 0; i < terminalSize && i < filesindir.size(); i++) {
                            consolevectorhandler::addToVector(filesindir[i]);
                        }
                    } else {
                        filedirectory = previousFileDirectory;
                        consolevectorhandler::updateScreen();
                        throw std::runtime_error("Not a directory");
                    }
                }
                catch (const std::exception& e) {
                    std::cout << "Error: " << filedirectory + "/" + consolevectorhandler::getSelectedFile() << " is not a directory" << std::endl;
                    log("Error: " + filedirectory + "/" + consolevectorhandler::getSelectedFile() + " is not a directory");
                    filedirectory = previousFileDirectory;
                    consolevectorhandler::updateScreen();
                }
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
                    int terminalSize = getTerminalSize(0);
                    for (int i = 0; i < terminalSize && i < filesindir.size(); i++) {
                        consolevectorhandler::addToVector(filesindir[i]);
                    }
                    consolevectorhandler::changeSelection(0, consolevectorhandler::getVectorLength());
                    consolevectorhandler::updateScreen();
                }
            }
            consolevectorhandler::updateScreen();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(16));  // Frame delay
    }

    return 0;
}