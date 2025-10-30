#include <iostream>
#include <stack>

bool isBalanced(const std::string& s){
    std::stack<char> c;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '[' || s[i] == '(' || s[i] == '{'){
            c.push(s[i]);
        }
        else{
            if(c.top() + 1 == s[i] || c.top() + 2 == s[i]){
                c.pop();
            }
            else{
                return false;
            }
        }
        
        
        
    }
    return c.empty();
}

int main()
{
    std::cout << isBalanced("({[]})") << '\n';  // 1 (true)
    std::cout << isBalanced("([)]") << '\n';    // 0 (false)
    std::cout << isBalanced("{[}]") << '\n';    // 0 (false)
}