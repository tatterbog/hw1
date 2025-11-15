#include <iostream>
#include <forward_list>
#include <utility>
#include <cmath>

class Polynomial{
    private:
        std::forward_list<std::pair<int, double>> fl;
    
    public:
        Polynomial(int val = 0, double c = 0.0){
            if(c != 0.0) {
                fl.push_front({val, c});
            }

        }

        void addTerm(int exp, double cof){
            for(auto &mem : fl){
                if(mem.first == exp){
                    mem.second += cof;
                    if(mem.second == 0.0){
                        fl.remove(mem);
                    }
                    return;
                }
            }

            if(cof != 0.0){
                fl.push_front({exp, cof});
            }

            fl.sort([](const auto &a, const auto &b){
                return a.first > b.first;
            });
        }

        double evaluate(double x) const {
            double res = 0.0;
            for(const auto &mem : fl){
                res += mem.second * pow(x, mem.first);
            }
            return res;
        }

        Polynomial derivative() const {
            Polynomial dv;
            for(const auto& mem : fl){
                if(mem.first != 0){
                    dv.addTerm(mem.first - 1, mem.first * mem.second);
                }
            }
            return dv;
        }

        void print() const {

            auto it = fl.begin();
            if((*it).second < 0){
                std::cout << "-";
            }

            while(it != fl.end()){
                if((*it).first == 0.0){
                    std::cout << abs((*it).second) << ' ';
                }
                    
                else if((*it).first == 1){
                    std::cout << abs((*it).second) << "x ";
                }
                    
                else{
                    std::cout << abs((*it).second) << "x^" << (*it).first << ' ';
                }

                
                auto nextIt = std::next(it);
                if(nextIt != fl.end()) {
                    if (nextIt->second > 0){ 
                        std::cout << "+ ";
                    } 
                    else{
                        std::cout << "- ";
                    }
                }
                it++;
            }
            std::cout << '\n';
        }
    
};

int main(){
    Polynomial p;
    p.addTerm(2, 3.0);  // 3x²
    p.addTerm(0, 5.0);  // +5
    p.addTerm(1, -2.0); // -2x
    p.print(); // "3x² - 2x + 5"
    double result = p.evaluate(2.0); // 3*4 - 2*2 + 5 = 13
    Polynomial dp = p.derivative(); // 6x - 2

    p.print(); // "3x² - 2x + 5"
    dp.print(); // "6x - 2"
}