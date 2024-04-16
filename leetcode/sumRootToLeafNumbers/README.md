
# Problem
Given the root of a binary tree

Return the sum of the all the root-to-leaf numbers

[\#129 Sum root to leaf numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers/?envType=daily-question&envId=2024-04-15)

## Constraint
- Each node is an int 0-9
- Sum max size is 32-bit integer
- Max tree depth is 10

## Approach
- DFS
1. Implement a pre-order traversal DFS
2. If node != NULL
    a. Push node into stack
    b. temp = temp * 10 + node.val
3. Else
    a. sum += temp
    b. temp /= 10
    c. Stack.pop
4. Return sum
