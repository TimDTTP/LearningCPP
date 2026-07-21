
# Problem
Given...
    - Vector\<vector\<int>>, grid
    - Integer, k

Return...
    - Vector\<vector\<int>>

Where...
Given the return is grid shifted k number of times.
- Elements are shifted 1 to the right
- If overflowed, move to the next spot below
- If grid\[i - 1]\[j - 1] move to grid\[0][0]

[#1260 Shift 2D grid](https://leetcode.com/problems/shift-2d-grid/description/?envType=daily-question&envId=2026-07-20)

## Constraint
- m == grid.length
- n == grid\[i].length
- 1 <= m <= 50
- 1 <= n <= 50
- -1000 <= grid\[i]\[j] <= 1000
- 0 <= k <= 100

## Approach
- add all values to a vector
- iterate starting at k and emplace all values with values in vector

Runtime
0ms beats 100%
Memory
19.40mb beats 11.39%

## Improvements

