#include <iostream>
#include <map>
#include <vector>

int removeInfrequent(std::map<std::string, int>& mp, int threshold){
    auto it = mp.begin();
    int removed = 0;
    while(it != mp.end()){
        if(it->second < threshold){
            removed++;
            it = mp.erase(it);
        }
        else{
            it++;
        }
    }
    return removed;
}

int main(){
    std::map<std::string, int> freq = {{"apple", 5}, {"banana", 2}, {"cherry", 8}, {"date", 1}};
    int removed = removeInfrequent(freq, 3);
    std::cout << removed << '\n';  // 2
    // freq теперь содержит: {{"apple", 5}, {"cherry", 8}}
}