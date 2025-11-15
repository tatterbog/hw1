#include <iostream>
#include <set>

int findClosest(std::set<int> s, int n){
    if(s.empty()){
        return -1;
    }
    
    auto it = s.lower_bound(n); 
    if (it == s.begin()) {
        return *it;
    }

    if (it == s.end()) {
        return *std::prev(it);
    }

    
    auto prev = std::prev(it);
    if(abs(*prev - n) < abs(*it - n)){
        return *prev;
    }

    if(abs(*prev - n) > abs(*it - n)){
        return *it;
    }

    return *it > *prev ? *prev : *it;
}

int main(){
    std::set<int> s = {1, 5, 10, 15, 20};
    std::cout << findClosest(s, 12) << '\n';  // 10
    std::cout << findClosest(s, 13) << '\n';   // 15
}
