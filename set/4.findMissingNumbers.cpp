#include <iostream>
#include <set>
#include <vector>


void print(const std::set<int>& s){
    for(auto it = s.begin(); it != s.end(); it++){
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}

auto findMissingNumbers(const std::vector<int>& nums, int n){
    std::set<int> s(nums.begin(), nums.end());
    for(int i = 1; i <= n; i++){
        if(s.find(i) == s.end()){
           s.insert(i); 
        }
        else{
            s.erase(i);
        }
    }
    return s;
}

int main(){
    std::vector<int> nums = {1, 3, 5, 6};
    auto result = findMissingNumbers(nums, 6);
    // result: {2, 4}
    print(result);
}