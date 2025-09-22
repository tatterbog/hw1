#include <iostream>
#include <vector>

class VectorStats {
private:
	std::vector<double> stats;

public:
	VectorStats(std::initializer_list<double> list) : stats(list) {}

	VectorStats(const std::vector<double>& vec) : stats(vec) {}

	double mean() {
		size_t len = stats.size();
		if(len == 0) {
			return 0;
		}

		double sum = 0;
		for(size_t i = 0; i < len; i++) {
			sum += stats[i];
		}
		return sum / len;
	}

	double median() const{
		size_t len = stats.size();
		if(len == 0) {
			return 0;
		}

		if (len % 2 == 0) {
			return (stats[len / 2 - 1] + stats[len / 2]) / 2.0;
		}
		return stats[len / 2];
	}

	void addValue(const double& value) {
		stats.push_back(value);
	}

	void removeValue(const double& value) {
		if(stats[0] == value) {
			stats.erase(stats.begin());
		}

		size_t j = 0;
		size_t len = stats.size();
		for(size_t i = 1; i < len; i++) {
			if(stats[i] == value) {
				j = i;
				break;
			}
		}

		if(j != 0) {
			stats.erase(stats.begin() + j);
		}
	}
	
	void print() const {
        for (double x : stats){
            std::cout << x << ' ';
        }
        std::cout << '\n';
    }
};

int main() {
	VectorStats stats({1.0, 2.0, 3.0, 4.0});
	double m = stats.mean();
	double md = stats.median();
	std::cout << "Mean: " << m << " Median: " << md << '\n';
	
	stats.addValue(5.0);
	stats.removeValue(2.0);
    
    stats.print();
}