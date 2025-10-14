#include <iostream>
#include <array>

void fillArray(std::array<int, 7>&  arr, int x){
    for(int i = 0; i < 7; i++){
        arr[i] = x;
    }
}

int main()
{
    std::array<int, 7> arr;
    int x = 42;
    fillArray(arr, x);
    
    for(int i = 0; i < 7; i++){
        std::cout << arr[i] << " ";
    }
    return 0;
}