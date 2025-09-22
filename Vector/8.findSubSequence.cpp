#include <iostream>
#include <vector>


int findSubsequence(const std::vector<int>& arr1, const std::vector<int>& arr2) {
	int i = 0, len1 = arr1.size();
	int j = 0, len2 = arr2.size();

	if (len2 == 0) {
		return 0;
	}

	while(i < len1) {
		if(arr1[i] == arr2[j]) {
			j++;
		}
		else {
			if (arr1[i] == arr2[0]) {
				j = 1;
			}
			else {
				j = 0;
			}
		}
		i++;

		if(j == len2) {
			return i - j;
		}
	}
	return -1;
}

int main() {
	std::vector<int> main_vec = {1, 2, 3, 4, 5, 6};
	std::vector<int> sub_vec = {3, 4, 5};

	int index = findSubsequence(main_vec, sub_vec);
	std::cout << index << '\n';
}