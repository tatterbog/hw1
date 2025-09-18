#include <iostream>
#include <array>

template<typename T, int N>
bool validateArray(const std::array<T, N>& arr, const T& min, const T& max) {
    for (int i = 0; i < N; i++) {
        if (arr[i] < min || arr[i] > max) {
            return false;
        }
    }
    return true;
}

int main() {
    std::array<int, 4> scores = {85, 92, 78, 96};
    bool valid = validateArray<int, 4>(scores, 0, 100);
    
    std::cout << std::boolalpha;
    std::cout << valid << '\n';

    return 0;
}
