#include <iostream>
#include <queue>

class MedianFinder{
    private:
        std::priority_queue<int> pq;
        std::priority_queue<int> pq2;

    public:
        MedianFinder() = default;

        void addNum(int n){
            if (pq.empty() || n <= pq.top()){
                pq.push(n);
            }
            else{
                pq2.push(-n);
            }

            if(!pq.empty() && !pq2.empty() && pq.top() > -pq2.top()) {
                int a = pq.top();
                pq.pop();

                int b = -pq2.top();
                pq2.pop();

                pq.push(b);
                pq2.push(-a);
            }

            
            if(pq.size() > pq2.size() + 1){
                pq2.push(-pq.top());
                pq.pop();
            }

            else if(pq2.size() > pq.size()){
                pq.push(-pq2.top());
                pq2.pop();
            }
        }

        double findMedian(){
            if((pq.size() + pq2.size()) & 1){
                return pq.top();
            }
            return (pq.top() - pq2.top()) / 2.0;
        }

};

int main(){
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    std::cout << mf.findMedian() << '\n';  // 1.5
    mf.addNum(3);
    std::cout << mf.findMedian() << '\n';  // 2.0
}