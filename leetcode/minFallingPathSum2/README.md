
# Problem
Given...
- A vector of vectors of integers "grid"
Return...
- An integer 

Which is the minimum sum of a falling path with non-zero shifts. Where no
adjacent chosen elements share the same column.

[\#1289 Miniumum falling path sum II](https://leetcode.com/problems/minimum-falling-path-sum-ii/description/)

## Constraints
- n == grid.length == grid[i].length
- 1 <= n <= 200
- -99 <= grid{i}{j} <= 99

## Approach (FAILED)
- DFS
1. Add grid[0] to stack
2. Run while !stack.empty()
3. Pop top of stack and add to sum + add next row into stack

Failure to come to a solution with the 1 hour time limit

## Solution
- Dynamic programming
Solve by mirroring array and for each row below the first, find minimum path
that is not adjacently above. At the end you should have an array with all the
sums of the minimum path for each column. Return the minimum value in the last
row.
