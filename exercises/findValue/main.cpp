#include <iostream>
#include <iterator>

// beginning of new function
int* findValue(int* begin, int* end, int val)
{
    for (int* iter{ begin }; iter != end; ++iter)
    {
        if (*iter == val)
            return iter;
    }
    
    return end;
}
// end of new function

int main()
{
    int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };

    // Search for the first element with value 20.
    int* found{ findValue(std::begin(arr), std::end(arr), 20) };

    // If an element with value 20 was found, print it.
    if (found != std::end(arr))
    {
        std::cout << *found << '\n';
    }

    return 0;
}