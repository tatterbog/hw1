#include <iostream>
#include <forward_list>

void print(const std::forward_list<int> &fl) {
    for (int x : fl) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

void moveElementsToFront(std::forward_list<int> &fl, int val){
    auto it = fl.begin();
    auto prev_it = fl.before_begin(); 

       while(it != fl.end()) {
            if (*it == val) {
                it = fl.erase_after(prev_it);
                fl.push_front(val);
            }
            else{
                prev_it = it; 
                it++;
            }
        }
}

int main() {
    std::forward_list<int> fl = {1, 3, 2, 3, 4, 3};
    moveElementsToFront(fl, 3);
    print(fl);
    return 0;
}

