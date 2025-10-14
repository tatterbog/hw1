#include <iostream>
#include <string>


std::string makeSentence(const std::string& last) {
    return last + ".";
}


template<typename... Rest>
std::string makeSentence(const std::string& first, const Rest&... rest) {
    return first + " " + makeSentence(rest...);
}

int main() {
    auto sentence = makeSentence("GNU's", "Not", "Unix");
    auto greeting = makeSentence("Hello", "world");

    std::cout << makeSentence("15", "wqe", "214") << "\n";
    std::cout << sentence << "\n";
    std::cout << greeting << "\n";
}