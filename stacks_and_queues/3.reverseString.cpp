#include <iostream>
#include <stack>
#include <cstring>

void reverseString(std::string& str){
    std::stack<char> s;
    for(int i = 0; i < str.size(); i++){
        s.push(str[i]);
    }
    
    for(int i = 0; i < str.size(); i++){
        str[i] = s.top();
        s.pop();
    }
}

int main()
{
    std::string s = "Hello";
    reverseString(s);
    std::cout << s << '\n';  // olleH
}