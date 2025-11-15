#include <iostream>
#include <set>

int rangeCount(const std::set<int>& s, int start, int end){
    
    if (s.empty() || start > end) {
        return 0;
    }
    
    auto it1 = s.lower_bound(start);
    auto it2 = s.upper_bound(end);

    int count = 0;
    while(it1 != it2){
        it1++;
        count++;
    }
    return count;
}

int main(){
    std::set<int> s = {1, 3, 5, 7, 9, 11, 13, 15};
    std::cout << rangeCount(s, 5, 11) << '\n';  // 4 (элементы: 5, 7, 9, 11)
}