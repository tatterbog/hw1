#include <iostream>
#include <map>

int main() {
    int n;
    std::cin >> n;
    std::map<int, int> mp;
    int left = 1;
    int max = 1;
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        auto it = mp.find(x);
        if (it == mp.end() || it->second < left) {
            mp[x] = i;
        }
        else {
            if (max < i - left) {
                max = i - left;
            }
            left = mp[x] + 1;
            mp[x] = i;
        }

    }
    if (max < n - left + 1) {
        max = n - left + 1;
    }
    std::cout << max;
}