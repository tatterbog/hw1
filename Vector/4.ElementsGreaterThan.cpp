#include <iostream>
#include <vector>

void print(const std::vector<int>& v) {
    for (int x : v) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

int removeElementsGreaterThan(std::vector<int>& arr, int n) {
    int x = 0;
    if (!arr.empty()) {
        while (arr.back() > n) {
            arr.pop_back();
            x++;
        }
    }
    return x;
}

int main() {
    
    std::vector<int> v = { 1, 3, 5, 7, 9 };
    int removed = removeElementsGreaterThan(v, 5);

    std::cout << "Removed: " << removed << '\n';
    return 0;
}