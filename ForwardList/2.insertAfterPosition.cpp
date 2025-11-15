#include <iostream>
#include <forward_list>


void print(const std::forward_list<int> &fl) {
    for (int x : fl) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}


bool insertAfterPosition(std::forward_list<int>& fl, size_t pos, int value) {
    auto it = fl.before_begin();

    for (size_t i = 0; i <= pos; i++) {
        if (it == fl.end()) {
            return false;
        }
        ++it;
    }
    
    fl.insert_after(it, value);
    return true;
}


int main()
{
    std::forward_list<int> fl = {1, 2, 3, 4};
    insertAfterPosition(fl, 1, 99);
    print(fl);
    return 0;
}