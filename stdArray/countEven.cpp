#include <iostream>
#include <array>

template<int N>

int countEven(const std::array<int, N>& arr){
    int even = 0;
    int len = arr.size();
    for(int i = 0; i < len; i++){
        if(!(arr[i] & 1)){
            even++;
        }
    }
    return even;
}

int main()
{
    std::array<int, 6> arr = {124128, 2, 3, 4, 6, 6};
    int count = countEven<6>(arr);
    
    std::cout << count;
    
}