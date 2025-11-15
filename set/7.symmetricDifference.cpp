#include <iostream>
#include <set>
#include <vector>


void print(const std::set<int>& s){
    for(auto it = s.begin(); it != s.end(); it++){
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}


auto symmetricDifference(const std::vector<int>& arr1, const std::vector<int>& arr2){
    std::set<int> s(arr1.begin(), arr1.end());
    for(int i = 0; i < arr2.size(); i++){
        if(s.find(arr2[i]) == s.end()){
            s.insert(arr2[i]);
        }
        else{
            s.erase(arr2[i]);
        }
    }
    return s;
}

int main(){
    std::vector<int> arr1 = {1, 2, 3, 4};
    std::vector<int> arr2 = {3, 4, 5, 6};
    auto result = symmetricDifference(arr1, arr2);
    // result: {1, 2, 5, 6}
    print(result);
}