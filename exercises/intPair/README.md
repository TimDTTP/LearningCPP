
# Problem

Question #1 of LearnCPP Chapter 14.3

Create a struct called IntPair that holds two integers. Add a member function named print that prints the value of the two integers.

The following program function should compile:
#include <iostream>

// Provide the definition for IntPair and the print() member function here

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

and produce the output:
p1: Pair(1, 2)
p2: Pair(3, 4)

***

Question #2 of LearnCPP Chapter 14.3
Add a new member function to IntPair named isEqual that returns a Boolean indicating whether one IntPair is equal to another.

The following program function should compile:
#include <iostream>

// Provide the definition for IntPair and the member functions here

int main()
{
	IntPair p1 {1, 2};
	IntPair p2 {3, 4};

	std::cout << "p1: ";
	p1.print();

	std::cout << "p2: ";
	p2.print();

	std::cout << "p1 and p1 " << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
	std::cout << "p1 and p2 " << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");

	return 0;
}

and produce the output:
p1: Pair(1, 2)
p2: Pair(3, 4)
p1 and p1 are equal
p1 and p2 are not equal 