#include <iostream>
#include <array>

template<typename T, int N>
void print(std::array<T, N>& arr){
    for(int i = 0; i < N; i++){
        std::cout << arr[i] << ' '; 
    }
    std::cout << '\n';
}


template<typename T, int N>
void reverseArray(std::array<T, N>& arr){
    for(int i = 0; i < N / 2; i++){
        T tmp = std::move(arr[i]);
        arr[i] = std::move(arr[N - i - 1]);
        arr[N - i - 1] = std::move(tmp);
    }
}

int main(){
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    reverseArray<int, 5>(arr);
    print<int, 5>(arr);

    std::array<std::string, 4> arr2 = {"Joseph", 
        "Polnareff", "Avdol", "Iggy"};
    reverseArray<std::string, 4>(arr2);
    print<std::string, 4>(arr2);
}
