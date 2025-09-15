#include <iostream>

template<typename T>
T findMax(const T& first) {
    return first;
}

template<typename T, typename... Rest>
auto findMax(const T& first, const Rest&... rest) {
    if (first > findMax(rest...)) {
        return first;
    }

    return findMax(rest...);
}

int main() {
    std::cout << findMax<int>(1, 11321, 123, 13) << "\n";
    std::cout << findMax<double>(1.123, 11321.325, 123.13, 1273.13) << "\n";
    std::cout << findMax<std::string>(std::string("wqe"),std::string( "doadsg"),
    std::string("whafwqe")) << "\n";
}