#include <iostream>
#include <vector>

template<typename T>
class MaxHeap {
private:
    std::vector<T> vec;

    void siftDown(int i) {
        while(true){
            int largest = i;

            if(leftChild(i) < vec.size() && vec[leftChild(i)] > vec[largest]){
                largest = leftChild(i);
            }

            if(rightChild(i) < vec.size() && vec[rightChild(i)] > vec[largest]){
                largest = rightChild(i);
            }

            if(largest != i){
                std::swap(vec[i], vec[largest]);
                i = largest;
            } 

            else{
                break;
            }
        }
    }

public:
    MaxHeap() = default;

    static MaxHeap(const std::vector<T>& data) {
        vec = data;
        for(int i = vec.size() / 2 - 1; i >= 0; --i){
            siftDown(i);
        }
    }

    static bool isHeap(const std::vector<T>& data){
        if(data.size() <= 1){
            return true;
        }

        for(int i = 0; i < data.size(); i++){
            if (leftChild(i) < data.size() && data[i] < data[leftChild(i)]){
                return false;
            }

            if(rightChild(i) < data.size() && data[i] < data[rightChild(i)]){
                return false;
            }
                
        }

        return true;
    }

    const T &top() {
        return vec[0];
    }

    void push(const T &x) {
        vec.push_back(x);
        int currentSize = vec.size() - 1;
        if (vec.size() == 1) return;
        while (vec[currentSize] > vec[parent(currentSize)]) {
            std::swap(vec[currentSize], vec[parent(currentSize)]);
            currentSize = parent(currentSize);
            if (currentSize == 0) {
                return;
            }
        }
    }

    void pop() {
        vec.front() = vec.back();
        vec.pop_back();
        int currentIndex = 0;
        while (vec[currentIndex] < vec[leftChild(currentIndex)] || vec[currentIndex] < vec[rightChild(currentIndex)]) {
            if (vec[leftChild(currentIndex)] > vec[rightChild(currentIndex)]) {
                std::swap(vec[currentIndex], vec[leftChild(currentIndex)]);
                currentIndex = leftChild(currentIndex);
            } else {
                std::swap(vec[currentIndex], vec[rightChild(currentIndex)]);
                currentIndex = rightChild(currentIndex);
            }
            if (currentIndex >= vec.size() - 1) {
                return;
            }
        }
    }

    static int parent(int i) {
        return (i - 1) / 2;
    }

    static int leftChild(int i) {
        return (i * 2 + 1);
    }

    static int rightChild(int i) {
        return (i + 1) * 2;
    }


    const T& top() const{
        return vec[0];
    } 

    size_t size() const{
        return vec.size();
    }

    bool empty() const{
        return vec.size() == 0;
    }      

    void clear(){
        vec.clear();
    }            
};

int main() {
    MaxHeap<int> hp;
    hp.push(10);
    hp.push(0);
    hp.push(-10);
    hp.push(20);
}
