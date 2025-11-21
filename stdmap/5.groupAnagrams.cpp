#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

auto groupAnagrams(const std::vector<std::string>& words){
    std::map<std::string, std::vector<std::string>> mp;
    
    std::vector<std::string> words2 = words;
    for (auto& el : words2) {
        std::sort(el.begin(), el.end());
    }

    for(int i = 0; i < words.size(); i++){
        mp[words2[i]].push_back(words[i]);
    }

    std::vector<std::vector<std::string>> result;
    for (auto el : mp) {
        result.push_back(el.second);
    }
    return  result;
}

void print(const std::vector<std::vector<std::string>>& vec){
    for(int i = 0; i < vec.size(); i++) {
        for(int j = 0; j < vec[i].size(); j++){
            std::cout << vec[i][j] << " "; 
        } 
        std::cout << '\n';
    }
    
}

int main(){
    std::vector<std::string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto result = groupAnagrams(words);
    // result: [["eat", "tea", "ate"], ["tan", "nat"], ["bat"]]
    print(result);
}