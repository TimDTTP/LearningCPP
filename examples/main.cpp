
#include <iostream>
#include <vector>


int main() {
    std::vector<int> v{ 1, 2, 3, 4, 5 };

    for (int value : v) {
        std::cout << value << '\n';
    }

    return 0;
}