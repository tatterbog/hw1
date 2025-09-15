#include <iostream>

class Logger{
    private:
        int x;
        std::string s;

    public:
        Logger(int x) : x(x), s(x, ' '){}
        
        template<typename T, typename... Rest>
        auto log(const T& first, const Rest&... rest){
            std::cout << s << first << '\n';
            log(rest...);
        }
        
        void log(){
            return;
        }
};

int main()
{
    Logger logger(4);
    logger.log("Hello", 42, 3.14, 'A');

    Logger lg(7);
    lg.log("awye7u", 4, "jiq", '1', 1.8);

    return 0;
}