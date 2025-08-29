
# Problem
Given...
    - A vector\<vector\<int>>

Return...
    - A vector\<vector\<int>>

Where...
    - The square matrix is re-organize into a manner of which the the diagonals
of the lower left triangle is in a non-increasing order; up to the center 
diagonal. The upper right triangle is in a non-decreasing order.

[\#3446 Sort Matrix by Diagonals](https://leetcode.com/problems/sort-matrix-by-diagonals/)

## Constraint
- grid.length == grid\[i].length == n
- 1 <= n <= 10
- -10^5 <= grid\[i]\[j] <= 10^5

## Approach
- Define constants; i.e. size
- Deal with the lower left triangle first
- From the corner, push values into a vector
- Sort the values
- Overwrite matrix with new sorted value
- Move onto next diagonal
- Repeat then move onto upper right triangle

Runtime:
2ms beats 94.14%
Memory:
41.85mB beats 94.53%

## Improvements
- Implementation of a min heap to handle top right
    - max heap to handle bottom left

