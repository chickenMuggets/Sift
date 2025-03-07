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
    for(int i = 0; i < dirContents.size(); i++) {
        std::cout << dirContents[i] << "\n";
    }

    std::cout << "Press any key to continue...";
    std::cin.get();
    return 0;
}