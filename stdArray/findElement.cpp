#include <iostream>
#include <array>

template<typename T, int N>
int findElement(const std::array<T, N>& arr, const T& t){
    for(int i = 0; i < N; i++){
        if(arr[i] == t){
            return i;
        }
    }
    return -1;
}

int main()
{
    std::array<int, 6> arr = {1, 2, 3, 4, 5, 6};
    std::cout << findElement<int, 6>(arr, 7) << '\n';
    
    std::array<std::string, 3> arr2 = {"arar", "wg8eq", "wuqye"};
    std::cout << findElement<std::string, 3>(arr2, std::string("wuqye")) << '\n';
    
}