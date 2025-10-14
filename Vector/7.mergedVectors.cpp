#include <iostream>
#include <vector>


void print(const std::vector<int>& arr) {
    for (const auto& x : arr) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}


auto mergeSortedVectors(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    std::vector<int> vec3;
    size_t i = 0, j = 0;
    size_t len1 = vec1.size(), len2 = vec2.size();
    while(i < len1 && j < len2){
        if(vec1[i] < vec2[j]){
            vec3.push_back(vec1[i]);
            i++;
        }
        else{
            vec3.push_back(vec2[j]);
            j++;
        }
    }
    
    while(i < len1){
        vec3.push_back(vec1[i]);
        i++;
    }
    
    while(j < len2){
        vec3.push_back(vec2[j]);
        j++;
    }
    
    return vec3;
    
}

int main() {
    std::vector<int> vec1 = {1, 3, 5, 7};
    std::vector<int> vec2 = {2, 4, 6, 8, 9};
    std::vector<int> merged = mergeSortedVectors(vec1, vec2);
    print(merged);
}