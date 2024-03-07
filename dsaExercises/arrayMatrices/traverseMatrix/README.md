
# Problem
Given an array matrix, traverse the matrix via recursion

[Link:](https://www.geeksforgeeks.org/traverse-a-given-matrix-using-recursion/)

## Approach
1. Recursion
    - Starting at 0 for both row and column,
    - Print arr[][]
    - If column < size
        - Call fcn(column + 1)
    - Else
        - Call fcn(row + 1, column = 0)
