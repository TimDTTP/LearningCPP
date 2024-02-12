
#include <iostream>



char approachInput() {
    std::cout << "Choose which approach to use:" << std::endl
              << "A) Infix to Postfix" << std::endl;

    std::cout << "Enter: ";
    char selection{};
    std::cin >> selection;

    if (!std::cin) {
        if (std::cin.eof())
            exit(0);
        std::cin.clear();
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << '\n' << std::endl;

    return selection;
}

void approachSelection() {

}

int main() {


    return 0;
}