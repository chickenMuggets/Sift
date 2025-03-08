#include <iostream>
#include <filesystem>
#include <vector>
#include "includes/getterminalsize.h"
#include "includes/getcontentsofdir.h"
#include "includes/getselectedcharacter.h"
#include "includes/consVectorHandler.h"

int main(int argc, char** argv) {
    std::string filedirectory;
    if (argc > 1) {
        filedirectory = argv[1];
    }
    else {
        #ifdef _WIN32
        filedirectory = "C:/";
        #else
        filedirectory = "/usr/"
        #endif   
    }
    std::vector<std::string> filesindir = getContentsInDir(filedirectory);

    for (int i = filesindir.size(); i > 0; i--) {
        consolevectorhandler::addToVector(filesindir[filesindir.size() - i]);
    }
    consolevectorhandler::updateScreen();

    std::cout << "Press any key to continue...";
    std::cin.get();
    return 0;
}