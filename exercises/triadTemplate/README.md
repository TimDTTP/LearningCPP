
# Problem

Given by LearnCPP Chapter 10.X

Create a class template named Triad that has 3 members of the same template type. Also create a function template named print that can print a Triad. The following program should compile:

int main()
{
	Triad t1{ 1, 2, 3 }; // note: uses CTAD to deduce template arguments
	print(t1);

	Triad t2{ 1.2, 3.4, 5.6 }; // note: uses CTAD to deduce template arguments
	print(t2);

	return 0;
}

With the following result:
(1, 2, 3)(1.2, 3.4, 5.6)
