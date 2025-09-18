#include <iostream>
#include <array>

template<typename T, int N>
bool compareArrays(const std::array<T, N>& arr1,
     const std::array<T, N>& arr2){

    int len = arr1.size();
    for(int i = 0; i < len; i++){
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
       
}

int main(){
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    std::array<int, 5> arr2 = {1, 2, 7, 4, 5};

    std::cout << std::boolalpha;
    std::cout << compareArrays<int, 5>(arr, arr2) << '\n';

    std::array<std::string, 4> arr3 = {"Joseph", 
        "Polnareff", "Avdol", "Iggy"};
    std::array<std::string, 4> arr4 = {"Joseph", 
        "Polnareff", "Avdol", "Iggy"};

    std::cout << compareArrays<std::string, 4>(arr3, arr4) << '\n';

}