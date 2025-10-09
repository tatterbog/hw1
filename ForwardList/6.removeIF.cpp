#include <iostream>
#include <forward_list>

void print(const std::forward_list<int> &fl) {
    for (int x : fl) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

template<typename Func>
int removeIf(std::forward_list<int> &fl, Func f){
    int count = 0;
    auto it = fl.begin();
    auto prev_it = fl.before_begin();
    
    while(it != fl.end()){
        if(f(*it)){
            it = fl.erase_after(prev_it);
            count++;
        }
        else{
            prev_it = it;
            it++;   
        }
    }
    return count;
}

bool isOdd(int x) { return x % 2 != 0; }

int main(){
    std::forward_list<int> fl = {1, 1, 3, 4, 5, 6};
    int removed = removeIf(fl, isOdd);
    print(fl);
    std::cout << removed << '\n';
}

