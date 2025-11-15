#include <iostream>
#include <vector>

void print(const std::vector<int>& v) {
    for (int x : v) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

auto createVectorFromInput() {
    std::vector<int> arr;
    int x = 0;
    while (true) {
        std::cin >> x;
        if (x == 0) {
            break;
        }
        arr.push_back(x);
    }

    return arr;
}

int main() {
    std::vector<int> arr = createVectorFromInput();

    print(arr);
    return 0;
}