#include <iostream>

int max() {
    return 0;
}

template<typename T, typename... Rest>
auto max(const T& first, const Rest&... rest) {
    if (first > max(rest...)) {
        return first;
    }

    return max(rest...);
}

int main() {
    std::cout << max(1, 11321, 123,13);
}