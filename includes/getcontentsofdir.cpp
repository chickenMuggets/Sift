#include <iostream>
#include <filesystem>
#include <vector>

std::vector<std::string> getContentsInDir(std::string directory) {
    try {
        std::vector<std::string> contents;
        for (const auto& entry : std::filesystem::directory_iterator(directory)) {
            // Store just the filename
            contents.push_back(entry.path().filename().string()); // Use filename() to get just the filename
        }
        return contents;
    }
    catch (std::filesystem::filesystem_error e) {
        std::cerr << "Error: " << e.what() << std::endl;
        #ifdef _WIN32
        std::vector<std::string> contents;
        for (const auto& entry : std::filesystem::directory_iterator("C:/")) {
            // Store just the filename
            contents.push_back(entry.path().filename().string()); // Use filename() to get just the filename
        }
        #else
        std::vector<std::string> contents;
        for (const auto& entry : std::filesystem::directory_iterator("/home/")) {
            // Store just the filename
            contents.push_back(entry.path().filename().string()); // Use filename() to get just the filename
        }
        #endif
        return contents;
    }
}