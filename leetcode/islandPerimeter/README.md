
# Problem
Given a row x col grid, (vector x vector), of integers 1 and 0

Return the perimeter of the island as an integer

Which 0 represents water, 1 represents land.

[\#463 Island perimeter](https://leetcode.com/problems/island-perimeter/description/?envType=daily-question&envId=2024-04-18)

## Constraints
- Cells are only connected by edges, not vertices
- Given grid is completely surrounded by water
- There is exactly one island
- There are no "lakes" in the island
- 1 <= row,col <= 100

## Approach
- Brute Force
1. Iterate through array
2. For each point, check surrounding up, down, left, right boxes
    - If 0 or out of bounds, increment count by 1

- Approach 2
1. Iterate through by row
2. For each '1', * 2 + 2 -> to get number of maximum number of sizes
3. In a vector, store index of '1's
4. For each overlapping '1' subtract 2 from max sum
5. If non-sequential, +2

PROBLEM:
DOES NOT ACCOUNT FOR GAPS IN A ROW, WHEREAS THE ISLAND IS NOT ATTACH CONTIGUOUSLY
Time O(n)
