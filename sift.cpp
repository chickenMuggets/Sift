#include <iostream>
#include <filesystem>
#include <vector>
#include "includes/getterminalsize.h"
#include "includes/getcontentsofdir.h"
#include "includes/getselectedcharacter.h"

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
    std::vector<std::string> dirContents = getContentsInDir(filedirectory);
    double originalLoopAmount = dirContents.size();
    double loopNumber = 0;
    for(int loopAmount = originalLoopAmount; loopAmount > 0; loopAmount--) {
        loopNumber++;
        std::cout << dirContents[loopNumber] << "\n";
    }
    std::cin.get();  // Wait for user input before exiting
    return 0;
}