#include <iostream>
#include <set>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, n;
    std::cin >> x >> n;

    std::set<int> trafs = {0, x};
    std::multiset<int> holes = {x};

    for(int i = 0; i < n; i++){
        int p;
        std::cin >> p;

        auto it = trafs.upper_bound(p);
        int r = *it;
        int l = *std::prev(it);

        auto old = holes.find(r - l);
        holes.erase(old);

        holes.insert(p - l);
        holes.insert(r - p);

        trafs.insert(p);

        std::cout << *prev(holes.end()) << " ";
    }
}
