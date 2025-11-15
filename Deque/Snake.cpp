#include <iostream>
#include <deque>
#include <cstdlib>
#include <utility>

class SnakeGame{
    private:
        int width, height;
        std::deque<std::pair<int, int>> poses;
        bool hasFood = false;
        std::pair<int, int> food;
        bool alive = true;

        void move(int newY, int newX){
            for(int i = 1; i < poses.size(); ++i) {
                if (poses[i].first == newY && poses[i].second == newX) {
                    alive = false;
                    return;
                }
            }
        }

        bool isBody(int y, int x) const {
            for (int i = 1; i < poses.size(); ++i) {
                if (poses[i].first == y && poses[i].second == x)
                    return true;
                }
            return false;
        }

    public:
        SnakeGame(int width, int height, int startY, int startX) : width(width), height(height){
            poses.push_back({startY, startX});
        }

        void moveUp(){
            int y = poses.front().first - 1;
            int x = poses.front().second;

            if (y < 0) {
                y = height - 1;
            }

            poses.push_front({y, x});
            if (hasFood && y == food.first && x == food.second){
                hasFood = false;
            } else{
                poses.pop_back();
            }

            move(y, x);
        }

        void moveDown(){
            int y = poses.front().first + 1;
            int x = poses.front().second;

            if (y >= height) {
                y = 0;
            }
            
            
            poses.push_front({y, x});
            if (hasFood && y == food.first && x == food.second){
                hasFood = false;
            } else{
                poses.pop_back();
            }

            move(y, x);
        }

        void moveRight(){
            int y = poses.front().first;
            int x = poses.front().second + 1;

            if (x >= width) {
                x = 0;
            }

            poses.push_front({y, x});
            if (hasFood && y == food.first && x == food.second){
                hasFood = false;
            } else{
                poses.pop_back();
            }

            move(y, x);
        }

        void moveLeft(){
            int y = poses.front().first;
            int x = poses.front().second - 1;

            if (x < 0) {
                x = width - 1;
            }

            poses.push_front({y, x});
            if (hasFood && y == food.first && x == food.second){
                hasFood = false;
            } else{
                poses.pop_back();
            }

            move(y, x);
        }

        void spawnFood(){
            if(hasFood){
                return;
            }

            if(poses.size() == width * height){
                alive = false;
                return;
            }

            while(true){
                int y = std::rand() % height;
                int x = std::rand() % width;

                bool exists = true;
                for(int i = 0; i < poses.size(); i++){
                    if(poses[i].first == y && poses[i].second == x){
                        exists = false;
                        break;
                    }
                    
                }
                if(exists){
                    food = {y, x};
                    hasFood = true;
                    return;
                }
            }
            
        }

        void print() const {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (y == poses.front().first && x == poses.front().second){
                    std::cout << '@';
                }
                    
                else if (isBody(y, x)){
                    std::cout << 'O';
                }
                    
                else if (hasFood && y == food.first && x == food.second){
                    std::cout << '*';
                }

                else{
                    std::cout << '.';
                }
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }

    bool isAlive() const {
        return alive;
    }
};


int main() {
    SnakeGame game(10, 6, 2, 3);
    game.spawnFood();

    while (game.isAlive()) {
        game.print();

        char c;
        std::cin >> c;
        if (c == 'w') {
            game.moveUp();
        }
        else if (c == 's'){
            game.moveDown();
        }
        else if (c == 'a') {
            game.moveLeft();
        }
        else if (c == 'd') {
            game.moveRight();
        }

        game.spawnFood();
    }

    std::cout << "Yee yee ahh\n";
}