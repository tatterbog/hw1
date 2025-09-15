#include <iostream>

template<typename T, typename... Rest>
T makeObject(Rest&&... rest) {
    return T(std::forward<Rest>(rest)...);
}

class Person {
    std::string name;
    int age;
public:
    Person(std::string n, int a) : name(std::move(n)), age(a) {}
    void print() const { std::cout << name << " is " << age << " years old\n"; }
};

int main() {
    auto person = makeObject<Person>("Alice", 25);
    person.print();

    std::string s = "Polnareff";
    auto person2 = makeObject<Person>(s, 30);
    person2.print();
}