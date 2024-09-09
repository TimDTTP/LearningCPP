
# Problem
Given...
- An integer, m
- An integer, n
- A list node, head

Return...
- A vector<vector<int>>

Where...
The return value is a matrix size m by n, which contains the values of head in
clockwise spiral order, starting from top-left.

[\#2326 Spiral Matrix IV](https://leetcode.com/problems/spiral-matrix-iv/description/?envType=daily-question&envId=2024-09-09)

## Constraints
- 1 <= m, n <= 10^5
- 1 <= m * n <= 10^5
- Number of nodes in head is between [1, m*n]
- 0 <= Node.val <= 1000

## Notes
- Remaining units should be -1
- No need to bound check if num will fit in matrix
- Val will fit int

## Approach
- Init matrix using .reserve m x n
- Occupy each value with -1
- Iterate through linked list while != nullptr
- Change value as long as it is == -1

Runtime:
188ms beats 6.66%
140.80mb beats 5.23%

## Online Solution
Instead of checking if each position is -1, it would of been more efficient to
just iterate based on boundaries of all 4 directions


