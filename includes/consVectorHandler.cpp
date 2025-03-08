#include <vector>
#include <iostream>

namespace consolevectorhandler {
    std::vector<std::string> consoleVector;
    int selectedFile = 0;
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
            if (consoleVector.size() - i == selectedFile) {
                std::cout << "\033[30m\033[47m" << consoleVector[consoleVector.size() - i] << "\033[40m\033[39m" << "\n";
            }
            else {
                std::cout << consoleVector[consoleVector.size() - i] << "\n";
            }
        }
    }
    void changeSelection(int newSelectionItem) {
        selectedFile = newSelectionItem;
    }
}