Write a class named Ball. Ball should have two private member variables, one to hold a color (default value: black), and one to hold a radius (default value: 10.0). Add 4 constructors, one to handle each case below:

int main()
{
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}


The program should produce the following result:
Ball(black, 10)
Ball(blue, 10)
Ball(black, 20)
Ball(blue, 20)