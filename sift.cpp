#include <iostream>
#include <filesystem>
#include <vector>
#include "includes/getterminalsize.h"
#include "includes/getcontentsofdir.h"

int main() {
    std::vector<std::string> dir = getContentsInDir();  // Get the list of directories/files
    double filenum = 0;

    // Print each directory/file with its index
    for (const auto& entry : dir) {
        filenum += 1;
        std::cout << filenum << ": " << entry << std::endl;
    }

    // Assuming getTerminalSize() returns a string or a number representing terminal width/height
    std::cout << "terminal size: " << getTerminalSize(0) << std::endl;

    std::cin.get();  // Wait for user input before exiting
    return 0;
}