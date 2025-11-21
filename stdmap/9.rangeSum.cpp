#include <iostream>
#include <map>
#include <vector>


int rangeSumMap(const std::map<int, int>& mp, int left, int right){
    auto it1 = mp.lower_bound(left);
    auto it2 = mp.upper_bound(right);

    int sum = 0;
    while(it1 != it2){
        sum += it1->second;
        it1++;
    }
    return sum;
}

int main(){
    std::map<int, int> m = {{1, 10}, {3, 20}, {5, 30}, {7, 40}};
    std::cout << rangeSumMap(m, 3, 7) << '\n';  // 90 (20 + 30 + 40)
    std::cout << rangeSumMap(m, 2, 4) << '\n';  // 20 (только ключ 3)
}