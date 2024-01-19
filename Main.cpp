#include <iostream>
#include "dictionary.h"
#include <map>

class Cat {
private:
	const char* name;

public:
	Cat(const char* name) : name(name) {
		
	}

	~Cat() {

	}

	const char* nameOf() {
		return name;
	}

	Cat operator= (const char* name) {
		return Cat(name);
	}
};

int main() {
	workbench::Dictionary<int, Cat> cationary = workbench::Dictionary<int, Cat>(4);
	Cat whiskers = "Whiskers";
	Cat noodle = "Noodle";

	cationary.add(10, noodle);
	cationary.add(6, whiskers);
	std::cout << cationary.get(6).nameOf() << std::endl;
	std::cout << cationary.get(10).nameOf() << std::endl;

	return 0;
}