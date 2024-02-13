
#include <iostream>
#include <unordered_map>
#include <stack>
#include <string>

class fixConversion {
private:
    // contains operators
    std::stack<char> opStack{};
    
    // solution return value
    std::string solution{};

    // dictates priority
    std::unordered_map<char, int> operators {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2}
    };

    // char or operator; assuming ONLY char or operators
    bool isChar(char i) {
        int temp{static_cast<int>(i)};

        if ((65 <= temp && temp <= 90) || (97 <= temp && temp <= 122)) {
            return true;
        }
        else
            return false;
    }

    bool isGreater(char var) {
        if (operators[opStack.top()] <= operators[var])
            return true;
        else
            return false;
    }

    // empty stack if )
    void emptyToParentheses() {
        while (opStack.top() != '(') {
            solution += opStack.top();
            opStack.pop();
        }
        // additional 1 time to pop '('
        opStack.pop();
    }

    // empty stack completely
    void emptyStack() {
        while (opStack.size() != 0) {
            solution += opStack.top();
            opStack.pop();
        }
    }

public:
    std::string inToPost(std::string_view expression) {
        for (char i : expression) {
            // handle variables
            if (isChar(i)) {
                solution = solution + i;
            }
            // handle operators
            else {
                // if stack empty
                if (opStack.size() == 0) {
                    opStack.push(i);
                }

                // if ')'; empty stack till '('
                else if (i == ')') {
                    emptyToParentheses();
                }

                // if priority > top() || '('; push stack
                else if (isGreater(i) || i == '(') {
                    opStack.push(i);
                }

                // if priority < top(); empty stack, push stack
                else if (!isGreater(i)) {
                    emptyStack();
                    opStack.push(i);
                }
            }
        }

        // end of string; thus, empty stack
        emptyStack();
        
        return solution;
    }

    std::string preToIn(std::string_view expression) {
        for (char i{expression.size() - 1}; i >= 0; i--) {
            std::cout << i << ' ';
        }

        return solution;
    }

    std::string preToPost(std::string_view expression) {

    }

    std::string postToPre(std::string_view expression) {

    }
};

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

void approachSelection(std::string_view expression) {
    class fixConversion solution;
    switch (approachInput()) {
        case ('A') : {
            std::cout << "The result of approach A:" << std::endl;
            std::cout << "> " << solution.inToPost(expression) << std::endl;
            break;
        }
        case ('B') : {
            std::cout << "The result of approach B:" << std::endl;
            std::cout << "> " << solution.preToIn(expression) << std::endl;
        }
    }
}

int main() {
    std::string expressionPrime{"((A+B)-C*(D/E))+F"};
    approachSelection(expressionPrime);

    return 0;
}