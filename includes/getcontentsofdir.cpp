#include <iostream>
#include <filesystem>
#include <vector>

std::vector<std::string> getContentsInDir(std::string directory) {
    std::cout << "Getting contents of directory: " << directory << "\n";
    std::vector<std::string> contents;
    std::cout << "Contents of directory: \n";
    for (const auto& entry : std::filesystem::directory_iterator(directory)) {
        // Store just the relative path or filename
        std::cout << "Found: " << entry.path().relative_path().string() << "\n";
        contents.push_back(entry.path().relative_path().string()); // Use relative_path() to remove the drive prefix
        std::cout << "Added: " << contents.back() << "\n";
    }
    std::cout << "Contents of directory: \n";
    return contents;
}