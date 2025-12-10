#include <iostream>
#include <queue>

struct Point {
    int x;
    int y;
};

auto kClosest(const std::vector<Point>& vec, int k){
    auto cmp = [](const Point& x, const Point& y) {
        return ((x.x * x.x) + (x.y * x.y)) > ((y.x * y.x) + (y.y * y.y)); 
    };

    std::priority_queue<Point, std::vector<Point>, decltype(cmp)> pq(cmp);

    for(int i = 0; i < k; i++){
        pq.push(vec[i]);
    }

    for(int i = k; i < vec.size(); i++){
        if(cmp(pq.top(), vec[i])){
            pq.pop();
            pq.push(vec[i]);
        }
    }

    std::vector<Point> res;
    for(int i = 0; i < k; i++){
        res.push_back(pq.top());
        pq.pop();
    }

    return res;
}

void print(const std::vector<Point>& vec){
    for(auto i : vec){
        std::cout << i.x << ',' << i.y << " ";
    }
    std::cout << '\n';
}

int main(){
    std::vector<Point> pts = {{1, 3}, {-2, 2}, {5, 8}};
    auto result = kClosest(pts, 2);
    print(result);
    // result: {{-2, 2}, {1, 3}}
    // Расстояния: (-2)²+(2)² = 8, (1)²+(3)² = 10, (5)²+(8)² = 89   
}