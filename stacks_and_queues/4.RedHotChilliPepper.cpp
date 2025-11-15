#include <iostream>
#include <queue>
#include <vector>

std::string hotPotato(const std::vector<std::string> players, int n){
    std::queue<std::string> q;
    for(const auto& p : players){
        q.push(p);
    }

    while(q.size() > 1){
        for(int i = 0; i < n - 1; i++){
            std::string p = q.front();
            q.pop();
            q.push(p);
        }
        q.pop();
    }
    return q.front();
}


int main(){
    std::vector<std::string> players = {"Alice", "Bob", "Charlie", "David"};
    std::cout << hotPotato(players, 7) << '\n';  // победитель
}