#include <iostream>

int sum() {
    return 0;
}

template<typename T, typename... Rest>
auto sum(const T& first, const Rest&... rest) {
    return first + sum(rest...);
}

int main() {
    std::cout << sum(1, 2, 5);
}