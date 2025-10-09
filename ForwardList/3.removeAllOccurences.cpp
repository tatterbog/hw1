#include <iostream>
#include <forward_list>


void print(const std::forward_list<int> &fl) {
    for (int x : fl) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

int removeAllOccurrences(std::forward_list<int>& fl, int val){
    int x = 0;
    fl.push_front(0);
    for(auto it = fl.begin(); it != fl.end(); ){
        auto it2 = std::next(it);
        if(it2 != fl.end() && *it2 == val){
            fl.erase_after(it);
            x++;
        }
        else{
            it++;
        }
    }
    fl.pop_front();
    return x;
}


int main()
{
    std::forward_list<int> fl = {1, 2, 3, 2, 4, 2, 2, 2, 2};
    int removed = removeAllOccurrences(fl, 2);
    print(fl);
    std::cout << removed << '\n';
    return 0;
}