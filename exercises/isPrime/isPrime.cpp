#include <iostream>
#include <cassert>
#include <cmath>

bool isPrime2(int x)
{
    // write this function using a for loop
    if ((x == 0) || (x == 1))
        return false;
    if (x == 2)
        return true;

    for (int i{ 2 }; i < x; ++i)
        {
            if (x % i == 0)
            {
                return false;
            }
        }
    return true;
}

// optimized version using the hint given in problem
bool isPrime(int x)
{
    if ((x == 0) || (x == 1))
        return false;
    if (x == 2)
        return true;

    // a non prime must have a divisor less than sqrt
    double squareRootX{ sqrt(x) };

    for (int i{ 2 }; i <= squareRootX; ++i)
        {
            if (x % i == 0)
            {
                return false;
            }
        }
    return true;
}

int main()
{
    assert(!isPrime(0));
    assert(!isPrime(1));
    assert(isPrime(2));
    assert(isPrime(3));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(!isPrime(9));
    assert(isPrime(11));
    assert(isPrime(13));
    assert(!isPrime(15));
    assert(!isPrime(16));
    assert(isPrime(17));
    assert(isPrime(19));
    assert(isPrime(97));
    assert(!isPrime(99));
    assert(isPrime(13417));

    std::cout << "Success!\n";

    return 0;
}