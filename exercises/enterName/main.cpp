#include <algorithm> // for std::sort
#include <iostream>
#include <string> // for std::string

// function that inputs a name and returns the name to main()
std::string userInput(int iter)
{   
    // iter + 1 so that program starts count at 1 not 0
    std::cout << "Enter name #" << iter + 1 << ": ";
    std::string name{};
    std::cin >> name;

    return name;
}

int main()
{
    // ask user for number of names
    std::cout << "How many names would you like to enter? ";
    int lenNames{}; // implicit conversion to std::size_t
    std::cin >> lenNames;


    // loops for next name + add to array
    std::string* array{ new std::string[lenNames]{} };
    for (int i{ 0 }; i < lenNames; ++i)
    {
        array[i] = userInput(i);
    }
    std::cout << '\n';


    // sort array
    // Cannot use std::begin + std::end
    std::sort(array, (array + lenNames));
    

    // print array
    std::cout << "Here is your sorted list:" << '\n';
    for (int i{ 0 }; i < lenNames; ++i)
    {
        std::cout << "Name #" << i + 1 << ": ";
        std::cout << array[i] << '\n';
    }

    // delete array
    delete[] array;

    return 0;
}