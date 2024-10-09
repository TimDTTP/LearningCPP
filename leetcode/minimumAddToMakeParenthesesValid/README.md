
# Problem
Given...
- A string, s

Return...
- A int

Where...
The return value is the minimum number of moves to make s valid

[#921. Minimum Add To Make Parenthese Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)

## Contraints
- 1 <= s.length <= 1000
- s\[i] is either '(' or ')'

## Approach
- Iterate through string and add '(' parentheses to stack
- If ')', pop top of stack
    - If stack is empty then increment counter and continue
- Finally if stack is !empty, counter += stack.size
