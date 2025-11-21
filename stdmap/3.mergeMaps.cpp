#include <iostream>
#include <map>
#include <vector>


auto mergeMaps(const std::map<std::string, int>& mp1, 
    const std::map<std::string, int>& mp2){

    std::map<std::string, int> mp(mp1.begin(), mp1.end());
    for(auto it = mp2.begin(); it != mp2.end(); it++){
        if(mp.find(it->first) == mp.end()){
            mp[it->first] = it->second;
        }
        else{
            mp[it->first] += it->second;
        }
    }
    return mp;
}

void print(const std::map<std::string, int>& mp){
    for(auto it = mp.begin(); it != mp.end(); it++) {
        std::cout << it->first << ": " << it->second << ", ";
    }
    std::cout << '\n';
}

int main(){
    std::map<std::string, int> map1 = {{"a", 1}, {"b", 2}, {"c", 3}};
    std::map<std::string, int> map2 = {{"b", 3}, {"c", 4}, {"d", 5}};
    auto result = mergeMaps(map1, map2);
    // result: {{"a", 1}, {"b", 5}, {"c", 7}, {"d", 5}}
    print(result);
}