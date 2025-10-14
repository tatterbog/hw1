#include <iostream>

template<typename T1, typename T2>
auto makePairList(const T1& a, const T2& b){
    return std::pair<T1, T2>(a, b);
}

template<typename T1, typename T2, typename... Rest>
auto makePairList(const T1& first, const T2& second, const Rest&... rest){
    return std::pair<T1, decltype(makePairList(second, rest...))>(
        first, makePairList(second, rest...)
    ); 
}


template<typename T>
void printPair(const T& value){
    std::cout << value;
}


template<typename T1, typename T2>
void printPair(const std::pair<T1, T2>& p){
    std::cout << "{" << p.first << ", ";
    printPair(p.second);
    std::cout << "}";
}


template<typename T>
void print(const T& value){
    printPair(value);
    std::cout << "\n";
}


int main(){
    
    auto pair1 = makePairList(5, 'c');
    auto pair2 = makePairList(5, 'c', 4.32);
    auto pair3 = makePairList(1, 2, 3, 4);

    print(pair1);
    print(pair2); 
    print(pair3); 
}
