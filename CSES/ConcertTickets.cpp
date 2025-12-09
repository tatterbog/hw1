#include <iostream>
#include <set>

int main(){
    int x, y;
    std::cin >> x >> y;

    int n;
    std::multiset<int> st;
    for(int i = 0; i < x; i++){
        std::cin >> n;
        st.insert(n);
    }


    for(int i = 0; i < y; i++){
        std::cin >> n;
        auto it = st.upper_bound(n); 

        if(it == st.begin()){
            std::cout << -1 << ' ';
        } 
        else{    
            std::cout << *std::prev(it) << ' ';
            st.erase(std::prev(it));   
        }
    }

}