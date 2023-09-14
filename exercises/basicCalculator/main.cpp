
#include <functional>
#include <iostream>
#include <limits>
#include <string>
using ArithmeticFunction = std::function<int(int, int)>;


// assign default values to ASCII code
enum class Operator {
    operator_add = 43,
    operator_subtract = 45,
    operator_multiply = 42,
    operator_divide = 47
};


// handles std::cin fail and extra char in buffer
void validateInput(bool valid) {
    if (!valid) {
        if (std::cin.eof())
            exit(0);

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // error message
        std::cout << "Invalid input, try again\n";
    }
    else
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


// get value
int userValue(int& pos) {
    int value{};
    bool valid{ false };

    // if std::cin does not fail, break out of loop
    while (!valid) {
        std::cout << "Please enter the ";
        
        // if pos 0 -> "first", pos 1 -> "second"
        switch(pos) {
            case 0:
                std::cout << "first";
                break;
            case 1:
                std::cout << "second";
                break;
            default:
                break;
        }

        std::cout << " number: ";
        std::cin >> value;

        // check if std::cin failed or not
        valid = static_cast<bool>(std::cin);
        validateInput(valid);
    }

    ++pos;
    return value;
}


// get operator input
Operator userOperator() {
    // if valid input has been provided
    bool valid{ false };


    Operator op{};
    char opInput{};

    while (!valid) {
        std::cout << "Enter the operator: ";
        std::cin >> opInput;

        
        valid = static_cast<bool>(std::cin);
        validateInput(valid);

        
        // check if std::cin failed or not; either can't find matching enum or not valid
        if(valid) {
            switch (static_cast<int>(opInput)) {
                case 43:
                    op = Operator::operator_add;
                    break;
                case 45:
                    op = Operator::operator_subtract;
                    break;
                case 42:
                    op = Operator::operator_multiply;
                    break;
                case 47:
                    op = Operator::operator_divide;
                    break;

                default:
                    valid = false;
                    std::cout << "Invalid input, try again\n";
                    break;
            }
        }
    }

    return op;
}


// operator functions
int add(int value1, int value2) {
    return (value1 + value2);
}
int subtract(int value1, int value2) {
    return (value1 - value2);
}
int multiply(int value1, int value2) {
    return (value1 * value2);
}
int divide(int value1, int value2) {
    return (value1 / value2);
}


ArithmeticFunction getArithmeticFunction(Operator op) {
    switch (op) {
        case Operator::operator_add      : return (&add);
        case Operator::operator_subtract : return (&subtract);
        case Operator::operator_multiply : return (&multiply);
        case Operator::operator_divide   : return (&divide); 

        default: std::cout << "error\n";
    }
}


int main() {
    int numOfInputs{ 0 };
    int value1{ userValue(numOfInputs) };
    int value2{ userValue(numOfInputs) };

    Operator op{ userOperator() };

    std::cout << "First: " << value1 << '\n';
    std::cout << "Second: " << value2 << '\n';
    std::cout << "Operator: " << static_cast<int>(op) << '\n';

    ArithmeticFunction opFcn{ getArithmeticFunction(op) };
    std::cout << "Your result is: " << opFcn(value1, value2) << '\n';



    return 0;
}