#include <iostream>

template<typename Func>
void applyAndPrint(Func func){
    std::cout << '\n';
}

template<typename Func, typename T, typename... Rest>
void applyAndPrint(Func func, const T& first, const Rest&... rest ){
    std::cout << func(first) << ' ';
    return applyAndPrint(func, rest...);
}

template<typename T>
T square(const T& x) {
    return x * x;
}

template<>
std::string square(const std::string& x){
    return x + "^2";
} 

int main() {
    applyAndPrint(square<int>, 2, 3, 4, 5);
    applyAndPrint(square<double>, 2.12, 3.6, 4.9, 5.17);
    applyAndPrint(square<std::string>, "asrq", "qwiu", "gdaq", 
        "sga8cq", "qwehaksb");
}
