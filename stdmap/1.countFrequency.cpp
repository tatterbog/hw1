#include <iostream>
#include <map>
#include <vector>


auto countFrequency(const std::vector<int>& nums){
    std::map<int, int> mp;
    for(int i = 0; i < nums.size(); i++){
        mp[nums[i]]++;
    }
    return mp;
}

void print(const std::map<int, int>& mp){
    for(auto it = mp.begin(); it != mp.end(); it++) {
        std::cout << it->first << ": " << it->second << ", ";
    }
    std::cout << '\n';
}

int main(){
    std::vector<int> nums = {4, 2, 3, 4, 2, 3, 4, 3, 1, 4};
    auto result = countFrequency(nums);
    // result: {1: 1, 2: 2, 3: 3, 4: 4}
    print(result);
}