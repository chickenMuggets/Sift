#include <iostream>
#include <filesystem>
#include <vector>

std::vector<std::string> getContentsInDir(std::string dir = "C:/") {
    std::vector<std::string> contents;
    for (const auto& entry : std::filesystem::directory_iterator(dir)) {
        // Store just the relative path or filename
        contents.push_back(entry.path().relative_path().string()); // Use relative_path() to remove the drive prefix
    }
    return contents;
}