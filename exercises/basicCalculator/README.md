
# Problem

Question #1 from LearnCPP Chapter 12.1

In this quiz, we’re going to write a version of our basic calculator using function pointers.

1a) Create a short program asking the user for two integer inputs and a mathematical operation (‘+’, ‘-‘, ‘*’, ‘/’). Ensure the user enters a valid operation.

1b) Write functions named add(), subtract(), multiply(), and divide(). These should take two integer parameters and return an integer.

1c) Create a type alias named ArithmeticFunction for a pointer to a function that takes two integer parameters and returns an integer. Use std::function, and include the appropriate header.

1d) Write a function named getArithmeticFunction() that takes an operator character and returns the appropriate function as a function pointer.

1e) Modify your main() function to call getArithmeticFunction(). Call the return value from that function with your inputs and print the result.