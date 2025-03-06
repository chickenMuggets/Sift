#include <iostream>
#include <filesystem>
#include <vector>

std::vector<std::filesystem::directory_entry> getContentsInDir(std::string dir = "C:/") {
    std::vector<std::filesystem::directory_entry> contents;
    for (const auto& entry : std::filesystem::directory_iterator(dir)) {
        contents.push_back(entry);
    }
    return contents;
}