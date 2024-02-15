
#include <iostream>
#include <unordered_map>
#include <stack>
#include <string>

class fixConversions;
char approachInput();
void approachSelection(std::string_view, int);

int main() {
    std::string infix{"((A+B)-C*(D/E))+F"};
    std::string prefix{"*-A/BC-/AKL"};

    std::string expressionPrime{infix};

    approachSelection(expressionPrime, expressionPrime.size());

    return 0;
}

void approachSelection(std::string_view expression, int size) {
    class fixConversions solution;
    switch (approachInput()) {
        case ('A') : {
            std::cout << "The result of approach A:" << std::endl;
            std::cout << "> " << solution.inToPost(expression, size) << std::endl;
            break;
        }
        case ('B') : {
            std::cout << "The result of approach B:" << std::endl;
            std::cout << "> " << solution.preToIn(expression, size) << std::endl;
            break;
        }
        case ('C') : {
            std::cout << "The result of approach C:" << std::endl;
            std::cout << "> " << solution.preToPost(expression, size) << std::endl;
            break;
        }
        case ('D') : {
            std::cout << "The result of approach D:" << std::endl;
            std::cout << "> " << solution.postToPre(expression, size) << std::endl;
            break;
        }
    }
}

char approachInput() {
    std::cout << "Choose which approach to use:" << std::endl
              << "A) Infix to Postfix" << std::endl
              << "B) Prefix to Infix" << std::endl;

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

class fixConversions {
private:
    // operator stack
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

        if (('a' <= temp && temp <= 'z') || ('A' <= temp && temp <= 'Z')) {
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
    std::string inToPost(std::string_view expression, int size) {
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

    std::string preToIn(std::string_view expression, int size) {
        std::stack<std::string> sStack{};

        for (int i{size - 1}; i >= 0; i--) {
            // if char
            if (isChar(expression[i])){
                sStack.push(std::string(1, expression[i]));
            }

            // if operator
            else {
                std::string temp{};

                // [operand 1] [operator] [operand 2]
                temp += '(';
                temp += sStack.top(); sStack.pop();
                temp += expression[i];
                temp += sStack.top(); sStack.pop();
                temp += ')';

                sStack.push(temp);
            }
        }

        return sStack.top();
    }


    std::string preToPost(std::string_view expression, int size) {
        std::stack<std::string> sStack{};

        for (int i{size - 1}; i >= 0; i--) {
            if (isChar(expression[i])) {
                sStack.push(std::string(1,expression[i]));
            }
            else {
                std::string temp{};

                temp += sStack.top(); sStack.pop();
                temp += sStack.top(); sStack.pop();
                temp += expression[i];

                sStack.push(temp);
            }
        }

        return sStack.top();
    }

    std::string postToPre(std::string_view expression, int size) {
        std::stack<std::string> sStack{};

        for (int i{size - 1}; i >= 0; i--) {
            if (isChar(expression[i])) {
                sStack.push(std::string(1, expression[i]));
            }
            else {
                std::string temp{};

                temp += expression[i];
                temp += sStack.top(); sStack.pop();
                temp += sStack.top(); sStack.pop();
                sStack.push(temp);
            }
        }
    }

};
