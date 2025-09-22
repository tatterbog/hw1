#include <iostream>
#include <vector>

void print(const std::vector<int>& v) {
    for (int x : v) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

void workWithVector() {
    std::vector<int> arr;
    for (int i = 0; i < 10; i++) {
        arr.push_back(i + 1);
        std::cout << "size: " << arr.size() << ' ';
        std::cout << ' ';
        std::cout << "capacity: " << arr.capacity() << ' ';
        std::cout << '\n';
    }
   
    print(arr);
    
}

int main() {
    
    workWithVector();

    return 0;
}