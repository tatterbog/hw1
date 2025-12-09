#include <iostream>
#include <set>

int main() {
    std::multiset<int> towerTopElement;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int cubeSize;
        std::cin >> cubeSize;
        // min element *it > cubeSize
        auto it = towerTopElement.upper_bound(cubeSize);
        if (it == towerTopElement.end()) {
            towerTopElement.insert(cubeSize);
        } else {
            towerTopElement.erase(it);
            towerTopElement.insert(cubeSize);
        }
    }
    std::cout << towerTopElement.size() << std::endl;
}