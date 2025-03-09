#include <iostream>
#include <filesystem>
#include <vector>

std::vector<std::string> getContentsInDir(std::string directory) {
    try {
        std::vector<std::string> contents;
        for (const auto& entry : std::filesystem::directory_iterator(directory)) {
            // Store just the relative path or filename
            contents.push_back(entry.path().relative_path().string()); // Use relative_path() to remove the drive prefix
        }
        return contents;
    }
    catch (std::filesystem::filesystem_error e) {
        std::cerr << "Error: " << e.what() << std::endl;
        #ifdef _WIN32
        std::vector<std::string> contents;
        for (const auto& entry : std::filesystem::directory_iterator("C:/")) {
            // Store just the relative path or filename
            contents.push_back(entry.path().relative_path().string()); // Use relative_path() to remove the drive prefix
        }
        #else
        std::vector<std::string> contents;
        for (const auto& entry : std::filesystem::directory_iterator("/home/")) {
            // Store just the relative path or filename
            contents.push_back(entry.path().relative_path().string()); // Use relative_path() to remove the drive prefix
        }
        #endif
        return contents;
    }
}