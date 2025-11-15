#include <iostream>
#include <set>
#include <vector>


void print(const std::set<int>& s){
    for(auto it = s.begin(); it != s.end(); it++){
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}

bool isSubset(const std::vector<int>& sub, const std::vector<int>& super){
    std::set<int> s(super.begin(), super.end());
    for(int i = 0; i < sub.size(); i++){
        if(s.find(sub[i]) == s.end()){
            return false;
        }
    }
    return true;
}

int main(){
    std::vector<int> subset = {1, 3, 5};
    std::vector<int> superset = {1, 2, 3, 4, 5};
    std::cout << isSubset(subset, superset) << '\n';  // 1 (true)

    std::vector<int> subset2 = {1, 6};
    std::cout << isSubset(subset2, superset) << '\n';  // 0 (false)
}