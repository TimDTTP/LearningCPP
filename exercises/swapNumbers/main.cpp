
#include <iostream>

void swap(int& a, int& b)
{
    int c{ a };
    a = b;
    b = c;
}

int main()
{
    int a{ 5 };
    int b{ 35 };

    swap(a, b);

    std::cout << "a: " << a << '\n'
              << "b: " << b << '\n';

    return 0;
}