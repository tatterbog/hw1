#include <iostream>
#include <array>


template<typename T, int Rows, int Cols, typename Func>
auto process2DArray(const std::array<std::array<T, Cols>, Rows>& arr, 
    Func f){

    std::array<std::array<T, Cols>, Rows> res;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            res[i][j] = f(arr[i][j]);
        }
    }
    return res;
}

template<typename T, int Rows, int Cols>
 void print(const std::array<std::array<int, Cols>, Rows>& mat){
    for(int i = 0; i < Rows; i++){
        for(int j = 0; j < Cols; j++){
            std::cout << mat[i][j] << ' '; 
        }
        std::cout << '\n';
    }
}

int doubleValue(int x) {
    return x * 2;
}

int main() {
    std::array<std::array<int, 3>, 3> matrix = {{
        {{1, 2, 3}},
        {{4, 5, 6}},
        {{7, 8, 9}}
    }};

    auto doubled = process2DArray<int, 3, 3>(matrix, doubleValue);
    print<int, 3, 3>(doubled);

}
