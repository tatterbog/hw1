#include <iostream>
#include <deque>
#include <cmath>

template<typename T>
void print(const std::deque<T>& deq){
    for (size_t i = 0; i < deq.size(); ++i) {
        std::cout << deq[i] << ' ';
    }
    std::cout << '\n';
}


template<typename T>
void rotateDeque(std::deque<T>& dq, int k){
    if(dq.empty()){
        return;    
    }
    
    int k1 = abs(k) % dq.size(); 
    if(k > 0){
        while(k1 != 0){
            dq.push_front(dq.back());
            dq.pop_back();
            k1--;
        }
    }
    
    
    else{
        while(k1 != 0){
            dq.push_back(dq.front());
            dq.pop_front();
            k1--;
        }
    }
    
}

int main(){
    std::deque<int> dq = {1, 2, 3, 4, 5};
    rotateDeque(dq, 2);
    print(dq);
    rotateDeque(dq, -1);
    print(dq);
    
}