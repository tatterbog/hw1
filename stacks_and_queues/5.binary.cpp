#include <iostream>
#include <queue>
#include <vector>

auto generateBinaryNumbers(int n){
    std::vector<std::string> res;
    std::queue<std::string> q;
    q.push("1");

    while(n > 0){
        std::string str = q.front();
        q.push(str + "0");
        q.push(str + "1");
        res.push_back(str);
        q.pop();
        n--;
    }
    return res;
}

int main(){
    auto result = generateBinaryNumbers(7);
    // result: {"1", "10", "11", "100", "101"}
    for(const auto& r : result){
        std::cout << r << '\n';
    }
}