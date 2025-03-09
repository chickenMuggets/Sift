#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <iomanip> // for std::put_time

int log(std::string message) {
    std::ofstream logFile;
    logFile.open("log.txt", std::ios_base::app);
    if (!logFile) {
        std::cerr << "Error: Could not open log file." << std::endl;
        return 1;
    }

    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%F %T", std::localtime(&now_c));
    logFile << "Logged at <" << buffer << ">: " << message << std::endl;
    logFile.close();
    return 0;
}