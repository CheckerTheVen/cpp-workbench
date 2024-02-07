#include <iostream>

#include "dictionary.cpp"

template <class T>
class C {
	T val;

public:
	C(const T&);
	T value();
};

template <class T>
C<T>::C(const T& val) :
	val(val) { }

template <class T>
T C<T>::value() {
	return val;
}

int value = 4;

void print(const int x) {
	std::cout << x << std::endl;
}

int main() {
	//workbench::KeyValuePair<int, int> a = workbench::KeyValuePair<int, int>(1, 2);

	//std::cout << a.key() << " " << a.value() << std::endl;

	int x = 4;
	print(value++);
	std::cout << value << std::endl;

	return 0;
}