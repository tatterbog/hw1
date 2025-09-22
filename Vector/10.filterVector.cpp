#include <iostream>
#include <vector>

template<typename T>
void print(const std::vector<T>& arr) {
	for (const auto& x : arr) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
}

template<typename T>
bool isEven(const T& x) {
	return x % 2 == 0;
}

template<>
bool isEven(const std::string& x) {
	return x.size() % 2 == 0;
}

template<typename T, typename Func>
auto filterVector(std::vector<T>& arr, Func f) {
	std::vector<T> vec;
	size_t len = arr.size();
	for(size_t i = 0; i < len; i++) {
		if(f(arr[i])) {
			vec.push_back(arr[i]);
		}
	}
	return vec;
}

int main() {
	std::vector<int> vec = {1, 2, 3, 4, 5, 6};
	std::vector<int> filtered = filterVector(vec, isEven<int>);

	print(filtered);

	std::vector<std::string> vec2 = {"Joseph", "Polnareff",
         "Avdol", "Iggy"};
	std::vector<std::string> filtered2 = filterVector(vec2, isEven<std::string>);
	print(filtered2);
}

