
# Problem

Question #1 from LearnCPP Chapter 14.8

Write a class named Ball. Ball should have two private member variables, one to hold a color, and one to hold a radius. Also write a function to print out the color and radius of the ball.

The following sample program should compile:
int main()
{
	Ball blue{ "blue", 10.0 };
	blue.print();

	Ball red{ "red", 12.0 };
	red.print();

	return 0;
}

and produce the result:
Ball(blue, 10)
Ball(red, 12)