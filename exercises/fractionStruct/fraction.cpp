#include <iostream>

// fraction struct
struct Fraction
{
    int numerator{};
    int denominator{};
};

// fraction function - fraction input from user
Fraction userInput()
{
    Fraction temp{};
    
    std::cout << "Enter a value for the numerator: ";
    std::cin >> temp.numerator;

    std::cout << "Enter a value for the denominator: ";
    std::cin >> temp.denominator;
    std::cout << '\n';

    return temp;
}

// fraction function - multiply 2 function together
// parameters are const references so they can't modify and doesn't copy struct
Fraction multiply(const Fraction& firstFraction, const Fraction& secondFraction)
{
    Fraction temp{};
    temp.numerator = firstFraction.numerator * secondFraction.numerator;
    temp.denominator = firstFraction.denominator * secondFraction.denominator;

    return temp;
}

// void function - print value
void printFraction(const Fraction& input)
{
    std::cout << "Your fractions multiplied together: ";
    std::cout << static_cast<int>(input.numerator) << " / " << static_cast<int>(input.denominator) << '\n';
}

int main()
{
    Fraction firstFraction{ userInput() };
    Fraction secondFraction{ userInput() };

    Fraction product{ multiply(firstFraction, secondFraction) };
    printFraction(product);

    return 0;
}
