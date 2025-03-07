#include <vector>
#include <iostream>

namespace consolevectorhandler {
    std::vector<std::string> addToVector(std::vector<std::string> vec, std::string str) {
        vec.push_back(str);
        return vec;
    }
    std::vector<std::string> updateVector(std::vector<std::string> vec, std::string str, int index) {
        vec[index] = str;
        return vec;
    }
    std::vector<std::string> removeFromVector(std::vector<std::string> vec, int index) {
        vec.erase(vec.begin() + index);
        return vec;
    }
    std::vector<std::string> clearVector(std::vector<std::string> vec) {
        vec.clear();
        return vec;
    }
}