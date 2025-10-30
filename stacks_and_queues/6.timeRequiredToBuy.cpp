#include <iostream>
#include <queue>

int timeRequiredToBuy(const std::vector<int>& ts, int n){
    std::queue<std::pair<int, int>> q;
    for(int i = 0; i < ts.size(); i++){
        q.push({i, ts[i]});
    }
    int x = 0;

    while(true){
        q.front().second--;
        x++;
        if(q.front().second){
            q.push(q.front());
        }
        else{
            if(q.front().first == n){
                break;
            }
        }
        q.pop();
    }

    return x;
}

int main(){
    std::vector<int> tickets1 = {2, 3, 2};
    std::cout << timeRequiredToBuy(tickets1, 2) << '\n';  // 6
// Объяснение:
// Секунда 1: человек 0 покупает билет (осталось 1), идёт в конец
// Секунда 2: человек 1 покупает билет (осталось 2), идёт в конец
// Секунда 3: человек 2 покупает билет (осталось 1), идёт в конец
// Секунда 4: человек 0 покупает билет (осталось 0), уходит
// Секунда 5: человек 1 покупает билет (осталось 1), идёт в конец
// Секунда 6: человек 2 покупает билет (осталось 0), уходит
// Ответ: 6

    std::vector<int> tickets2 = {5, 1, 1, 1};
    std::cout << timeRequiredToBuy(tickets2, 0) << '\n';  // 8
// человек 0 должен купить 5 билетов, остальные по 1
}