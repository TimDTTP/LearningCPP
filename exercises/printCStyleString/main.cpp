
#include <iostream>

// print function
// decays into pointer
void printString(const char* myString) {
    int i{ 0 };

    while (true) {
        if ((*(myString + i)) == '\0') {
            break;
        }

        // print
        std::cout << *(myString + i) << ' ';

        // iterate to next letter
        ++i;
    };

    std::cout << '\n';
}


int main() {
    char myString[]{ "Hello world" };

    printString(myString);

    return 0;
}

/* Further improvement:
- No need to instantiate 'i', just point the pointer to next address
*/