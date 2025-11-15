#include <iostream>
#include <vector>

void manageCapacity(std::vector<int>& arr) {
    std::cout << "size: " << arr.size() << "\n";
    std::cout << "capacity: " << arr.capacity() << "\n";

    arr.reserve(arr.size() + 500);

    for (int i = 0; i < 500; i++) {
        arr.push_back(i + 1);
    }

    std::cout << '\n';
    std::cout << "size: " << arr.size() << "\n";
    std::cout << "capacity: " << arr.capacity() << "\n";
}

int main() {
    
    std::vector<int> v = { 1, 3, 5, 7, 9 };

    manageCapacity(v);

    return 0;
}