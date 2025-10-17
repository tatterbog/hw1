#include <iostream>
#include <deque>

void print(const std::deque<int>& deq){
    for (size_t i = 0; i < deq.size(); ++i) {
        std::cout << deq[i] << ' ';
    }
    std::cout << '\n';
}

void removeFromBothEnds(std::deque<int>& dq, size_t k){ 
    while(!dq.empty() && k != 0) {
        print(dq);
        std::cout << "Size: " << dq.size() << '\n';
        
        dq.pop_back();
        if(!dq.empty()){
            dq.pop_front();
        }
        k--;
       
    }
    print(dq);
    std::cout << "Size: " << dq.size() << '\n';
}

int main(){
    std::deque<int> dq = {1, 2, 3, 4, 5, 6, 7};
    removeFromBothEnds(dq, 3);
}