#include <iostream>
#include <forward_list>


void print(const std::forward_list<int> &fl) {
    for (const int& x : fl) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}


void insertionSort(std::forward_list<int>& fl){
    if(fl.empty()){
        return;
    }
    
    
    auto end = fl.begin();
    while (std::next(end) != fl.end()) {
        auto curr = std::next(end);
        
        if (*curr >= *end) {
            end = curr;
        } 

        else{
            int key = *curr;
            fl.erase_after(end);
            print(fl);
            auto prev = fl.before_begin();
            auto it = fl.begin();
            while (it != end && *it < key) {
                prev = it;
                it++;
            }
            fl.insert_after(prev, key);
            print(fl);
        }
    }
}


int main()
{
    std::forward_list<int> fl = {5, 5, 2, 8, 1, 9};
    print(fl);
    insertionSort(fl);
}