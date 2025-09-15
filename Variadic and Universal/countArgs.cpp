#include <iostream>

int countArgs() {
    return 0;
}

template<typename T, typename... Rest>
auto countArgs(const T& first, const Rest&... rest) {
    return countArgs(rest...) + 1;
}

int main() {
    std::cout << countArgs(1, 2, 5) << '\n';
    std::cout << countArgs(1.123, 11321.325, 123.13, 1273.13) << "\n";
    std::cout << countArgs("q0w", "72q", "g9sa", "2801", "ij0qwj") << '\n';
}