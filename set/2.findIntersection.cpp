#include <iostream>
#include <set>
#include <vector>


void print(const std::set<int>& s){
    for(auto it = s.begin(); it != s.end(); it++){
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}

auto findIntersection(const std::vector<int>& arr1, const std::vector<int>& arr2){
    std::set<int> s(arr1.begin(), arr1.end());
    std::set<int> set2;
    for(int i = 0; i < arr2.size(); i++){
        if(s.find(arr2[i]) != s.end()){
            set2.insert(arr2[i]);
        }
    }
    return set2;
}

int main(){
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> arr2 = {3, 4, 5, 6, 7};
    auto result = findIntersection(arr1, arr2);
    // result: {3, 4, 5}
    print(result);
}