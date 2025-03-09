#include <vector>
#include <iostream>

namespace consolevectorhandler {
    std::vector<std::string> consoleVector;
    int selectedFile = 0;
    void addToVector(std::string newString) {
        consoleVector.push_back(newString);
    }
    void updateVector(std::string newString, double updateNum) {
        consoleVector[updateNum] = newString;
    }
    void updateScreen() {
        std::cout << "\033[H\033[J";

        for (std::size_t i = 0; i < consoleVector.size(); i++) {
            if (i == selectedFile) {
                std::cout << "\033[30m\033[47m" << consoleVector[i] << "\x1b[0m\n";  // Highlight selection
            } else {
                std::cout << consoleVector[i] << "\n";
            }
        }
    }
    int getCurrentSelected() {
        return selectedFile;
    }
    void changeSelection(int newSelectionItem) {
        selectedFile = newSelectionItem;
    }
    void clearConsoleVector() {
        consoleVector.clear();
    }
}