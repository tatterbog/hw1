#include <iostream>
#include <set>
#include <vector>

auto removeDuplicates(const std::vector<int>& nums){
    std::set<int> s;
    for(int i : nums){
        s.insert(i);
    }
    return s;
}

void print(const std::set<int>& s){
    for(auto it = s.begin(); it != s.end(); it++){
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}

int main(){
    std::vector<int> nums = {4, 2, 5, 2, 3, 4, 1};
    auto result = removeDuplicates(nums);
    // result: {1, 2, 3, 4, 5}
    print(result);

}