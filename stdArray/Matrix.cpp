#include <iostream>
#include <array>

class Matrix3x3{
    private:
        std::array<std::array<int, 3>, 3> mat;
    
    public:
     template <typename... Args>
        Matrix3x3(Args... args) {
            int arr[9] = {args...};
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    mat[i][j] = arr[i * 3 + j]; 
                }
            }
        }

        void transpose() {
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < i; j++){
                    int tmp = mat[i][j];
                    mat[i][j] = mat[j][i];
                    mat[j][i] = tmp; 
                }
            }
        }

        int getElement(int row, int col) const {
            return mat[row][col];
        }


        void setElement(int row, int col, int value) {
            mat[row][col] = value;
        }

        void print() const {
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    std::cout << mat[i][j] << ' '; 
                }
                std::cout << '\n';
            }
        }

        std::array<int, 3>& operator[](int index) {
            return mat[index];
        }

        const std::array<int, 3>& operator[](int index) const {
            return mat[index];
        }
};

int main(){
    Matrix3x3 matrix(1, 2, 3, 4, 5, 6, 7, 8, 9);
    matrix.print();
    matrix.transpose();
    matrix.print();
}