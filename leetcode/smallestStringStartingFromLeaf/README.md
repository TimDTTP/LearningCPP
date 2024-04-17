
# Problem
Given the root of a binary tree

Return the lexicographically smallest string, from leaf node to root

Where the binary tree is a tree of integers 0-25, representing alphabet letters.

[\#988 Smallest string starting from leaf](https://leetcode.com/problems/smallest-string-starting-from-leaf/?envType=daily-question&envId=2024-04-17)

## Constraints
- 0 <= node.val <= 25

## Approach
- DFS
1. Search for leaf nodes while tracking 2 variables
    - One variable appends value as it goes
    - Another tracks the the string
2. If the int value is smaller than current smallest, then replace it
3. This should repeat recursively
