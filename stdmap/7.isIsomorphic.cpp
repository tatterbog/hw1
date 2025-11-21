#include <iostream>
#include <map>
#include <vector>

bool isIsomorphic(const std::string& str1, const std::string& str2){
    if(str1.size() != str2.size()){
        return false;
    }

    std::map<char, char> mp;
    std::map<char, char> mp2;
    for(int i = 0; i < str1.size(); i++){
        if(mp.find(str1[i]) != mp.end()){
            if(mp[str1[i]] != str2[i]){
                return false;
            }
        }

        if(mp2.find(str2[i]) != mp2.end()){
            if(mp2[str2[i]] != str1[i]){
                return false;
            }
        }

        mp[str1[i]] = str2[i];
        mp2[str2[i]] = str1[i];
    }
    return true;
}


int main(){
    std::cout << isIsomorphic("egg", "add") << '\n';     // 1 (true)
    std::cout << isIsomorphic("foo", "bar") << '\n';     // 0 (false)
    std::cout << isIsomorphic("paper", "title") << '\n'; // 1 (true)
}