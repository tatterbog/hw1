#include <iostream>

int sum() {
    return 0;
}

template<typename T, typename... Rest>
auto sum(const T& first, const Rest&... rest) {
    return first + sum(rest...);
}

int main() {
    std::cout << sum(1, 2, 5) << "\n";
    std::cout << sum(1.2, 2.4, 15.41, 134.91) << "\n";
    std::cout << sum(1.5f, 2, 3.2) << "\n";    
}