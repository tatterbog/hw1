#include <iostream>
#include <stack>
#include <cstring>
#include <vector>

int evaluateRPN(const std::vector<std::string>& expr){
    std::stack<int> s;
    for(int i = 0; i < expr.size(); i++){
        if(expr[i] == "*"){
            double x = s.top();
            s.pop();
            double y = s.top();
            s.pop();
            s.push(y * x);

        }
        
        else if(expr[i] == "+"){
            double x = s.top();
            s.pop();
            double y = s.top();
            s.pop();
            s.push(y + x);

        }
        else if(expr[i] == "-"){
            double x = s.top();
            s.pop();
            double y = s.top();
            s.pop();
            s.push(y - x);
        
        }
        
        else if(expr[i] == "/"){
            double x = s.top();
            s.pop();
            double y = s.top();
            if(y == 0){
                throw std::runtime_error("Division by zero");
            }
            s.pop();
            s.push(y / x);
            
        }
        
        else{
            s.push(atoi(expr[i].c_str()));
        }
    }
    return s.top();
}

int main()
{
    std::vector<std::string> expr = {"2", "1", "+", "3", "*"};
    std::cout << evaluateRPN(expr) << '\n';  // 9
    // (2 + 1) * 3 = 9
}