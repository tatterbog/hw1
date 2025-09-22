#include <iostream>
#include <vector>

class DynamicMatrix {
private:
	std::vector<std::vector<int>> mat;

public:
	DynamicMatrix(size_t row = 0, size_t col = 0) {
		mat = std::vector<std::vector<int>>(row, std::vector<int>(col, 0));
	}

	int getElement(size_t row, size_t col) {
		return mat.at(row).at(col);
	}

	void setElement(size_t row, size_t col, int value) {
		if(row < mat.size() && col < mat[0].size()) {
			mat[row][col] = value;
		}
	}

	void addRow() {
		size_t cols = 0;
		if (!mat.empty()) {
			cols = mat[0].size();
		}
		mat.resize(mat.size() + 1, std::vector<int>(cols, 0));
	}

	void addColumn() {
		size_t len1 = mat.size(), len2 = mat[0].size();
		for(size_t i = 0; i < len1; i++) {
			mat[i].resize(len2 + 1, 0);
		}
	}

	void print() {
		for (const auto& m : mat) {
			for (int x : m) {
				std::cout << x << ' ';
			}
			std::cout << '\n';
		}
	}
};

int main() {

	DynamicMatrix matrix(3, 3);
	matrix.setElement(1, 1, 42);
	matrix.setElement(1, 2, 67);
	matrix.addRow();
	matrix.addColumn();
    
	matrix.print();
}

