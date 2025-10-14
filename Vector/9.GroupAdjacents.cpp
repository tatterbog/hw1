#include <iostream>
#include <vector>

void print(std::vector<std::vector<int>> vec){
    for (const auto& v : vec) {
        for (int x : v) {
            std::cout << x << ' ';
        }
        std::cout << '\n';
    }
}

auto groupAdjacent(const std::vector<int>& vec) {
    std::vector<std::vector<int>> adjGroups;
    std::vector<int> group;
    
    group.push_back(vec[0]);
    size_t len = vec.size();
    
    for (size_t i = 1; i < len; i++) {
        if (vec[i] == vec[i - 1]) {
            group.push_back(vec[i]);
        } 
        else {
            adjGroups.push_back(group);
            group.clear();
            group.push_back(vec[i]);
        }
    }

    adjGroups.push_back(group);
    return adjGroups;
}

int main() {
    std::vector<int> vec = {1, 1, 2, 2, 2, 3, 1, 1};
    std::vector<std::vector<int>> groups = groupAdjacent(vec);
    
    print(groups);
}