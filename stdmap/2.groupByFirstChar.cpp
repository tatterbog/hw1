#include <iostream>
#include <map>
#include <vector>


auto groupByFirstChar(const std::vector<std::string>& words){
    std::map<char, std::vector<std::string>> mp;
    for(int i = 0; i < words.size(); i++){
        mp[words[i][0]].push_back(words[i]);
    }
    return mp;
}

void print(const std::map<char, std::vector<std::string>>& mp){
    for(auto it = mp.begin(); it != mp.end(); it++) {
        std::cout << it->first << ": "; 
        for(int i = 0; i < it->second.size(); i++){
            std::cout << it->second[i] << " "; 
        } 
        std::cout << '\n';
    }
    
}

int main(){
    std::vector<std::string> words = {"apple", "banana", "apricot", "cherry", "avocado"};
    auto result = groupByFirstChar(words);
    // result: {'a': ["apple", "apricot", "avocado"], 'b': ["banana"], 'c': ["cherry"]}
    print(result);
}