
# Problem
Given a string of '(', '[', '{', ')', ']', '}'...
Return a bool if string is properly closed by bracket/parentheses pair

## Note
Only consists of the characters listed above
Open brackets must be closed in the respective order

[\#20 Valid Parentheses](https://leetcode.com/problems/valid-parentheses/description/)

## Approaches
- Stacks
1. While loop through string
2. If "opening" bracket, add to stack
3. If "closing" bracket, if not top of stack, return false
    - Violates 2 qualifier
