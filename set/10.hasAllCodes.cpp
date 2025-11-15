#include <iostream>
#include <set>


bool hasAllCodes(const std::string &s, int k) {
    int pow = 1 << k;
    if (s.size() < pow) {
        return false;
    }
    std::string result;
    std::set<std::string> st;
    for (int i = 0; i < s.size() - k; i++) {
        result = s.substr(i, k);
        st.insert(result);
    }
    return st.size() == pow;
}


int main(){
    std::cout << hasAllCodes("00110110", 2) << '\n';  // 1 (true)
    // Двоичные коды длины 2: "00", "01", "10", "11"
    // Все найдены: "00" (индекс 0), "01" (индекс 1), "11" (индекс 5), "10" (индекс 3)

    std::cout << hasAllCodes("0110", 1) << '\n';      // 1 (true)
    // Двоичные коды длины 1: "0" и "1"
    // Оба присутствуют в строке

    std::cout << hasAllCodes("0110", 2) << '\n';      // 0 (false)
    // Двоичные коды длины 2: "00", "01", "10", "11"
    // Отсутствует "00"

    std::cout << hasAllCodes("0000000001011100", 4) << '\n';  // 0 (false)
    // Не все 16 возможных кодов длины 4 присутствуют
}