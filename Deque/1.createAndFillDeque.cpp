#include <iostream>
#include <deque>

void print(const std::deque<int>& deq){
    for (size_t i = 0; i < deq.size(); ++i) {
        std::cout << deq[i] << ' ';
    }
    std::cout << '\n';
}

auto createAndFillDeque(size_t N){
    std::deque<int> dq;
    for(size_t i = 0; i < N; i++) {
        if(i & 1){
            dq.push_back(i);
        }
        else{
            dq.push_front(i);
        }
    }
    return dq;
}

int main(){
    std::deque<int> dq = createAndFillDeque(10);
    print(dq);
}