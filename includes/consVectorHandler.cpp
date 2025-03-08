#include <vector>
#include <iostream>

namespace consolevectorhandler {
    std::vector<std::string> consoleVector;
    void addToVector(std::string newString) {
        consoleVector.push_back(newString);
    }
    void updateVector(std::string newString, double updateNum) {
        consoleVector.at(updateNum) = newString;
    }
    void updateScreen() {
        std::cout << "\033[H";
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
        for(int i = consoleVector.size(); i > 0; i--) {
            std::cout << consoleVector[consoleVector.size() - i] << "\n";
        }
    }
    
}