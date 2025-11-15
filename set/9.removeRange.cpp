#include <iostream>
#include <set>
#include <vector>


int removeRange(std::set<int>& s, int start, int end){
    if (s.empty() || start > end) {
        return -1;
    }

    auto it1 = s.lower_bound(start);
    auto it2 = s.upper_bound(end);

    int count = 0;
    while(it1 != it2){
        auto it = it1;
        it1++;
        s.erase(*it);
        count++;
        
    }
    return count;
}

int main(){
    std::set s = {1, 3, 5, 7, 9, 11, 13, 15};
    int removed = removeRange(s, 5, 11);
    std::cout << removed << '\n';  // 4
    // s теперь содержит: {1, 3, 13, 15}
}