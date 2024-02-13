
# Problem

Conversion between postfix, prefix, and infix expressions

[Link](https://www.geeksforgeeks.org/convert-infix-expression-to-postfix-expression/)

## Approach
1. Infix to postfix
    - Iterate through string
    - If != var, add to postfix
    - If == operator, add to stack
        - If operator < stack.top(), empty stack
        - Add operator to stack
    - Add opening parenthesis to stack
    - If closing parenthesis, empty till opening parenthesis
    - If end, empty stack
2. Prefix to infix
    - Iterate through string reverse
    - If variable, add to stack
    - If operator, pop 2 operands and concatenate in string surrounded by "()"
3. Prefix to postfix
4. Postfix to prefix