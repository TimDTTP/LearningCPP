
# Problem
Given int x...

return bool, if x is a palindrome number

[\#9 Palindrome Number](https://leetcode.com/problems/palindrome-number/)

## Ideas to approach problem
- Utilize 2 stacks
1. Push values into 1 stack
2. Pull half into another stack
3. Compare top values

- 2 Pointers approach
1. Push values into a vector
2. Use 1 pointer at the beginning, 1 at the end
3. If values match, increment/decrement the pointers
4. If p1 + 2 > p2; quit and return
