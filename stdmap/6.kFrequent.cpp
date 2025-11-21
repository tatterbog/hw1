#include <iostream>
#include <map>
#include <vector>
#include <algorithm>


auto topKFrequent(const std::vector<int>& nums, int k){
    std::map<int, int> mp;
    for(int i = 0; i < nums.size(); i++){
        mp[nums[i]]++;
    }

    std::vector<std::pair<int, int>> pairs;
    for(auto it = mp.begin(); it != mp.end(); it++){
        pairs.push_back({it->first, it->second});
    }

    std::sort(pairs.begin(), pairs.end(),
        [](const std::pair<int,int>& a, const std::pair<int,int>& b){
            return a.second > b.second;  
        }
    );

    std::vector<int> res;
    for(int i = 0; i < k && i < pairs.size(); i++){
        res.push_back(pairs[i].first);
    }
    return res;
}

void print(const std::vector<int>& vec){
    for(int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << '\n';
}

int main(){
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    auto result = topKFrequent(nums, 2);
    // result: {1, 2}
    print(result);
}