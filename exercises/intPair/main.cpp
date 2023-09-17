#include <iostream>

struct IntPair {
    int numOne{};
    int numTwo{};

    void print() {
        std::cout << "Pair(" << numOne << ", " << numTwo << ")\n";
    }
};

int main()
{
	IntPair p1 {1, 2};
	IntPair p2 {3, 4};

	std::cout << "p1: ";
	p1.print();

	std::cout << "p2: ";
	p2.print();

	return 0;
}