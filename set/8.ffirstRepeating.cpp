#include <iostream>
#include <set>
#include <vector>

int firstRepeating(const std::vector<int>& nums){
    std::set<int> s;
    for(int i = 0; i < nums.size(); i++){
        if(s.find(nums[i]) == s.end()){
            s.insert(nums[i]);
        }
        else{
            return nums[i];
        }
    }
    return -1;
}

int main(){
    std::vector<int> nums = {1, 2, 3, 4, 2, 5, 6, 3};
    std::cout << firstRepeating(nums) << '\n';  // 2
}