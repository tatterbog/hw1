#include <iostream>
#include <forward_list>


void print(const std::forward_list<int> &fl) {
    for (const int& x : fl) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

auto createAndFillList(size_t n){
    
    std::forward_list<int> ls;

    for(size_t i = 0; i < n; i++){
        ls.push_front(i + 1);
    }
    return ls;
    
}


int main()
{
    auto ls = createAndFillList(5);
    print(ls);
    return 0;
}