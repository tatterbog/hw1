#include <iostream>
#include <array>

template<int N>
auto countFrequency(const std::array<char, N>& arr) {
    std::array<int, 256> fr = {};

    for (int i = 0; i < N; i++) {
        fr[arr[i] - '\0']++;
    }

    return fr;
}

int main() {
    std::array<char, 5> text = {'h', 'e', 'l', 'l', 'o'};
    auto freq = countFrequency<5>(text);

    std::cout <<  freq['h'] << ' ' << 
    freq['e'] << ' ' << 
    freq['l'] << ' ' << 
    freq['o'] << "\n";

    return 0;
}
