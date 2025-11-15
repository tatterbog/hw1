#include <iostream>
#include <vector>

void print(const std::vector<int>& v) {
    for (int x : v) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

auto createAndFillVector(int N) {
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }   
    return arr;
}


int main() {
    int N;
    std::cin >> N;
    print(createAndFillVector(N));
}