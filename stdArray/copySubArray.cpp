#include <iostream>
#include <array>

template<typename T, int N>
void print(std::array<T, N>& arr){
    for(int i = 0; i < N; i++){
        std::cout << arr[i] << ' '; 
    }
    std::cout << '\n';
}

template<typename T, int N, int M>
std::array<T, M> copySubArray(const std::array<T, N>& arr, int first,
     int count){
    std::array<T, M> arr2;
    if(first + M > N){
        return {};
    }

    for(int i = 0; i < count; i++){
        arr2[i] = arr[first + i];
    }
    return arr2;
}

int main(){
    std::array<int, 10> source = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto sub = copySubArray<int, 10, 5>(source, 2, 5);
    print<int, 5>(sub);

    std::array<std::string, 4> source2 = {"Joseph", 
        "Polnareff", "Avdol", "Iggy"};
    auto sub2 = copySubArray<std::string, 4, 3>(source2, 1, 3);
    print<std::string, 3>(sub2);

    std::array<int, 5> source3 = {1, 2, 3, 4, 5};
    auto sub3 = copySubArray<int, 5, 6>(source3, 2, 6);
    print<int, 6>(sub3);
}