#include <iostream>
#include <vector>
#include <queue>

auto heapSort(const std::vector<int>& vec){
    std::vector<int> res;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    
    for (int num : vec) {
        pq.push(num);
    }
    for(int i = 0; i < vec.size(); i++){
        res.push_back(pq.top());
        pq.pop();
    }
    
   
    return res;
}


void print(const std::vector<int>& vec){
    for(int i : vec){
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::vector<int> nums = {4, 2, 8, 1, 9, 3};
    auto result = heapSort(nums);
    print(result);
    return 0;
}