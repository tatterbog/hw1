#include <iostream>
#include <vector>

template<typename T>
void print(const std::vector<T>& arr) {
    for (const auto& x : arr) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

template<typename T>
void resizeVector(std::vector<T>& arr, size_t len, const T& el) {
    print(arr);
    arr.resize(len, el);
    print(arr);
}

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9};
    resizeVector(arr, 3, 8);
    
    std::vector<std::string> arr2 = {"qjwgie", "uew9yq", "agdso"};
    resizeVector<std::string>(arr2, 5, "wqgei");

}