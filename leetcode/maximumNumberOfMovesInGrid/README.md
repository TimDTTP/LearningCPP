
# Problem
Given...
- A vector\<vector\<int>>, grid

Return...
- An integers

Where...
the return value is the max number of moves you can perform with the following
rules.
- Start at any cell in the first column
- Possible moves could be...
    - \(row - 1, col + 1)
    - \(row, col + 1)
    - \(row + 1, col + 1)
- The next cell must strictly be greater than the value of the current cell

[#2684 Maximum Number of Moves in a Grid](https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/)

## Constraints
- m == grid.length
- n == grid\[i].length
- 2 <= m, n <= 1000
- 4 <= m * n <= 10^5
- 1 <= grid\[i]\[j] <= 10^6

## Approach
Recursive DFS
- Loop through first column
- Call recusive function for each
- Bound check each direction before going
- If last column and is greater, return counter
- Check above, middle, then below
- If cell is greater than current, call recursive function with new parameters
