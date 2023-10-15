
#include <iostream>
#include <stack>

int main() {
    std::stack<int> stack;
    stack.push(1);
    stack.push(52);
    stack.push(3);

    for (int i{0}; i < 3; ++i) {
        std::cout << stack.top() << '\n';
        stack.pop();
    }


    return 0;
}
