#include <iostream>
#include <limits> // for std::numeric_limits

// input loop + clear input buffer
int clientInput()
{
    int userInput{};

    do
    {
        std::cout << "Enter a number within 1 and 9: ";
        std::cin >> userInput;

        // if the user entered something invalid
        if (std::cin.fail())
        {
            std::cin.clear(); // reset any error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer
        }
    }
    while (userInput <= 0 || userInput >= 10);

    return userInput;
}

// print array
void printArray(const int array[9], int size)
{
    for (int i{ 0 }; i < size; ++i)
        std::cout << array[i] << ' ';

    std::cout << '\n';
}

// search array index value
int findIndex(int input, const int array[9], int size) // pass by value, because fundamental type
{
    int index{};
    for (int i{ 0 }; i < size; ++i)
    {
        if (array[i] != input)
            continue;
        else
            index = i;
    }
    return index;
}

int main()
{
    constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
    int arraySize{ std::size(array) };

    int number{ clientInput() };
    printArray(array, arraySize);

    std::cout << "The number " << number << " has index " << findIndex(number, array, arraySize) << '\n';


    return 0;
}