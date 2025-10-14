#include <iostream>
#include <array>

std::array<int, 5> createArray(){
    return {1, 2, 3, 4, 5};
}

int main()
{
    auto arr = createArray();
    
    for(int i = 0; i < 5; i++){
        std::cout << arr[i] << " ";
    }
}