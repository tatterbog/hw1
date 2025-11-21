#include <iostream>
#include <map>
#include <vector>


int firstUniqueChar(const std::string str){
    std::map<char, int> mp;
    for(int i = 0; i < str.size(); i++){
        mp[str[i]]++;
    }

    for(int i = 0; i < str.size(); i++){
        if(mp[str[i]] == 1){
            return i;
        }
    }

    return -1;
}

int main(){
    std::string s = "leetcode";
    std::cout << firstUniqueChar(s) << '\n';  // 0 ('l')

    std::string s2 = "loveleetcode";
    std::cout << firstUniqueChar(s2) << '\n';  // 2 ('v')
}