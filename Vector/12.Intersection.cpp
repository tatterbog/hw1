#include <iostream>
#include <vector>

void print(const std::vector<int>& arr) {
	for (int x : arr) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
}

auto findIntersection(std::vector<int>& arr, std::vector<int>& arr2) {
	std::vector<int> intersected;
	size_t i = 0, j = 0;

	size_t len1 = arr.size(), len2 = arr2.size();
	while (i < len1 && j < len2) {
		if (arr[i] == arr2[j]) {
			if (intersected.empty() || intersected.back() != arr[i]) {
				intersected.push_back(arr[i]);
			}
			i++;
			j++;
		}
		else if (arr[i] < arr2[j]) {
			i++;
		}
		else {
			j++;
		}
	}

	return intersected;
}

int main() {
	std::vector<int> a = {1, 2, 3, 4, 5};
	std::vector<int> b = {3, 4, 5, 6};

	std::vector<int> inter = findIntersection(a, b);
	print(inter);
}

