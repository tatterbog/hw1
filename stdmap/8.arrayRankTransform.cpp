#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

auto arrayRankTransform(const std::vector<int>& nums){
    std::map<int, int> mp;
    std::vector<int> vec = nums;
    std::sort(vec.begin(), vec.end());

    int j = 1;
    for(int i = 0; i < vec.size(); i++){
        if(mp.find(vec[i]) == mp.end()){
            mp[vec[i]] = j;
            j++;
        }
    }

    std::vector<int> res(vec.size());
    for(int i = 0; i < res.size(); i++){
        res[i] = mp[nums[i]];
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
    std::vector<int> arr = {40, 10, 20, 30};
    auto result = arrayRankTransform(arr);
    // result: {4, 1, 2, 3}
    print(result);

    std::vector<int> arr2 = {100, 100, 100};
    auto result2 = arrayRankTransform(arr2);
    // result2: {1, 1, 1}
    print(result2);
}