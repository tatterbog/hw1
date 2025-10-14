#include <iostream>
#include <forward_list>

void print(const std::forward_list<int> &fl) {
    for (int x : fl) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

void mergeSortedLists(std::forward_list<int>& fl1, std::forward_list<int>& fl2) {
    if (fl1.empty()) {
        fl1 = std::move(fl2);
        return;
    }

    auto before1 = fl1.before_begin();
    auto curr1 = fl1.begin();
    auto curr2 = fl2.begin();

    while (curr2 != fl2.end()) {
        if (curr1 == fl1.end() || *curr2 < *curr1) {
            curr1 = fl1.insert_after(before1, *curr2);
            ++curr2;
        } else {
            ++before1;
            ++curr1;
        }
    }

    fl2.clear(); 
}

int main() {
    std::forward_list<int> fl1 = {1, 3, 5};
    std::forward_list<int> fl2 = {2, 4, 6};
    mergeSortedLists(fl1, fl2);
    print(fl1); 
}