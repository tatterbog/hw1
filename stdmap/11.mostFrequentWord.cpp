#include <iostream>
#include <map>
#include <vector>


std::string mostFrequentWord(const std::string& str){
    std::map<std::string, int> mp;
    std::string word;
    for(int i = 0; i < str.size(); i++){    
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
            word += (str[i] >= 'A' && str[i] <= 'Z') ? str[i] - 'A' + 'a' : str[i];
        }

        else{
            if(word.size()) {
                mp[word]++;
                word = "";
            }
        }
    }

    if(word.size()) {
        mp[word]++;
        word = "";
    }

    int most = 0;
    for(auto it = mp.begin(); it != mp.end(); it++){
        if (it->second > most) {
            most = it->second;
            word = it->first;
        }
    }

    return word;
}

int main(){
    std::string text = "Bob hit a ball, the Hit BALL flew far after it was HIT.";
    std::cout << mostFrequentWord(text) << '\n';  // "hit"
}