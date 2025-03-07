#include <vector>
#include <iostream>

namespace consolevectorhandler {
    std::vector<std::string> addToVector(std::vector<std::string> vec, std::string str);

    std::vector<std::string> updateVector(std::vector<std::string> vec, std::string str, int index);

    std::vector<std::string> removeFromVector(std::vector<std::string> vec, int index);

    std::vector<std::string> clearVector(std::vector<std::string> vec);
}