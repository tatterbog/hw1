#include <iostream>

template<typename T>
void foo(T &l_value) {
    std::cout << l_value << " [lvalue]" << '\n';
}

template<typename T>
void foo(T &&r_value) {
    std::cout << r_value << " [rvalue]" << '\n';
}

void betterPrint(){
    return;
}

template<typename T, typename... Rest>
void betterPrint(T&& first, Rest&&... rest) {
    foo(std::forward<T>(first));
    betterPrint(std::forward<Rest>(rest)...);
}

int main() {
    int x = 5;
    betterPrint(x, 100, "hello");

    std::string s = "hello";
    betterPrint(9.1, s, 'q');
}