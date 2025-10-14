#include <iostream>
#include <array>

template<typename T, int N>
void print(const std::array<T, N>& arr){
    for(int i = 0; i < N; i++){
        std::cout << arr[i] << ' '; 
    }
    std::cout << '\n';
}

template<typename T, int N>
void shiftLeft(std::array<T, N>& arr, int pos){
    for (int i = 0; i < pos; i++) {
        T first = arr[0];
        for (int j = 0; j < N - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[N - 1] = first;
    }
}

int main(){
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    shiftLeft<int, 5>(arr, 2);
    print<int, 5>(arr);
}