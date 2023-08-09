#include <iostream>
#include <iterator> // for std::size

void bubbleSort(int array[9], int arraySize)
{
    // if array is completely sorted
    bool sorted{ false };

    // keeps track of how many iterations has gone by
    int iteration{ 0 };

    while (sorted == false)
    {
        // if no elements are reorganized, exit while loop
        sorted = true;

        // goes through each number to compare
        // initiate with iteration, which will not re-check organized values
        for (int i{ 0 }; i < (arraySize - 1); ++i)
        {
            if (array[i] > array[i + 1])
            {
                sorted = false; // elements have been reorganized
                std::swap(array[i], array[i + 1]);
            }
        }

        // adds another iteration
        ++iteration;
    }

    std::cout << "Early termination on iteration " << iteration << '\n';
}

void printArray(const int array[9], int arraySize)
{
    for (int nums{ 0 }; nums < arraySize; ++nums)
        std::cout << array[nums] << ' ';

    std::cout << '\n';
}

int main()
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    int arraySize{ std::size(array) };

    bubbleSort(array, arraySize);

    printArray(array, arraySize);

    return 0;
}