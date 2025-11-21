#include <iostream>
#include <map>

template<typename T1, typename T2>
class BidirectionalMap{
    private:
        std::map<T1, T2> front;
        std::map<T2, T1> back;

    public:
        void insert(const T1& key, const T2& value){
            if(front.find(key) == front.end()){
                back.erase(front[key]);
            }

            if(back.find(value) == back.end()){
                front.erase(back[value]);
            }

            front[key] = value;
            back[value] = key;
        }

        T2 getByKey(const T1& key) const {
            return front[key];
        }

        T1 getByValue(const T2& value) const {
            return back[value];
        }

        void removeByKey(const T1& key){
            back.erase(front[key]);
            front.erase(key);
        }

};


int main(){
    BidirectionalMap<int, std::string> bm;
    bm.insert(1, "one");
    bm.insert(2, "two");
    std::cout << bm.getByKey(1) << '\n';      // "one"
    std::cout << bm.getByValue("two") << '\n'; // 2
}