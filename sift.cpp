#include <iostream>
#include <filesystem>
#include <vector>
#include "includes/getterminalsize.h"
#include "includes/getcontentsofdir.h"

int main() {
    std::vector<std::filesystem::directory_entry> dir = getContentsInDir();

    for (const auto& entry : dir) {
        std::cout << entry.path() << std::endl;
    }
    std::cin.get();
    return 0;
}