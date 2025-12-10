#include <iostream>
#include <vector>
#include <queue>

auto mergeKSortedvecs(const std::vector<std::vector<int>>& vecs){

    std::priority_queue<std::pair<int, std::pair<int,int>>> pq; 

    for (int i = 0; i < vecs.size(); i++){
        if(!vecs[i].empty()){
            pq.push({-vecs[i][0], {i, 0}});
        }
    }

    std::vector<int> res;

    while(!pq.empty()){
        int i = pq.top().second.first;
        int j = pq.top().second.second;

        res.push_back(-pq.top().first);
        pq.pop();
      
        if(j + 1 < vecs[i].size()){
            pq.push({-vecs[i][j + 1], {i, j + 1}});
        }
        
    }

    return res;
}

void print(const std::vector<int>& vec){
    for(int i : vec){
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

int main(){
    std::vector<std::vector<int>> vecs = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}
    };
    auto result = mergeKSortedvecs(vecs);
    print(result);
    // result: {1, 1, 2, 3, 4, 4, 5, 6} 
}