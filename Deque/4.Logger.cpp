#include <iostream>
#include <deque>

class Logger{
    private:
        std::deque<std::string> logs;
        size_t N;

    public:
        Logger(size_t n): N(n) {}

        void add(const std::string& log){
            if(logs.size() == N){
                logs.pop_front();
            }

            logs.push_back(log);
        }

        void show() const {
            for(size_t i = 0; i < logs.size(); i++){
                std::cout << logs[i] << ' ';
            }
            std::cout << '\n';
        }


        
};

int main(){
    Logger log(3);
    log.add("start");
    log.add("init");
    log.add("run");
    log.add("stop");
    log.show();
}