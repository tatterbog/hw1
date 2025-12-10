#include <iostream>
#include <vector>
#include <queue>

auto kthSmallest(const std::vector<int>& vec, int k){

    std::priority_queue<int> pq;
    
    for (int i = 0; i < k; i++){
        pq.push(vec[i]);
    }
    
    for(int i = k; i < vec.size(); i++){
         if (vec[i] < pq.top()){
            pq.pop();
            pq.push(vec[i]);  
        }
    }
    
    return pq.top();
}


int main(){
    std::vector<int> nums = {7, 10, 4, 3, 20, 15, -1, 8};
    int k = 4;
    std::cout << kthSmallest(nums, k) << '\n';  
}