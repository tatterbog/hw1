#include <iostream>

template<typename T>
class CircularDeque {
    T* _data{};
    int _size = 0;
    int _capacity = 0;
    int head = 0;
    int rear = 0;

public:
    explicit CircularDeque(int n = 0) : _capacity(n) {
        if (_capacity == 0) _capacity = 1;
        _data = static_cast<T*>(::operator new(_capacity * sizeof(T)));
    }

    void push_back(const T& var) {
        if (_size == _capacity) {
            int newCapacity = _capacity * 2;
            if (newCapacity == 0) newCapacity = 1;

            T* _dataCP = static_cast<T*>(::operator new(newCapacity * sizeof(T)));
            for (int i = 0; i < _size; ++i)
                new(_dataCP + i) T(std::move(_data[(head + i) % _capacity]));

            for (int i = 0; i < _size; ++i)
                _data[(head + i) % _capacity].~T();

            ::operator delete(_data);
            _data = _dataCP;
            _capacity = newCapacity;
            head = 0;
            rear = _size;
        }

        new(_data + rear) T(var);
        rear = (rear + 1) % _capacity;
        _size++;
    }

    void pop_back() {
        if (_size == 0) return;
        rear = (rear - 1 + _capacity) % _capacity;
        _data[rear].~T();
        _size--;
    }

    void push_front(const T& var) {
        if (_size == _capacity) {
            int newCapacity = _capacity * 2;
            if (newCapacity == 0) newCapacity = 1;

            T* _dataCP = static_cast<T*>(::operator new(newCapacity * sizeof(T)));
            for (int i = 0; i < _size; ++i)
                new(_dataCP + i) T(std::move(_data[(head + i) % _capacity]));

            for (int i = 0; i < _size; ++i)
                _data[(head + i) % _capacity].~T();

            ::operator delete(_data);
            _data = _dataCP;
            _capacity = newCapacity;
            head = 0;
            rear = _size;
        }

        head = (head - 1 + _capacity) % _capacity;
        new(_data + head) T(var);
        _size++;
    }

    void pop_front() {
        if (_size == 0) return;
        _data[head].~T();
        head = (head + 1) % _capacity;
        _size--;
    }

    T& operator[](size_t i) {
        return _data[(head + i) % _capacity];
    }

    int size() const { return _size; }

    ~CircularDeque() {
        if (_data) {
            for (int i = 0; i < _size; ++i)
                _data[(head + i) % _capacity].~T();
            ::operator delete(_data);
        }
    }
};

int main() {
    CircularDeque<int> d(2);

    d.push_back(1);
    d.push_back(1);
    d.push_back(4);
    d.push_back(4);

    std::cout << d[0] << '\n';
    std::cout << d[1] << '\n';
    std::cout << d[2] << '\n';
    std::cout << d[3] << '\n';

    d.pop_back();
    d.push_back(5);
    std::cout << d[3] << '\n';
}
