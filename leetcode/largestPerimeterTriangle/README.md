
# Problem
Given...
    - vector\<int>, nums

Return...
    - int

Where...
nums is a list of possible lengths of a side of a triangle. Return the largest 
perimeter of a triangle with a non-zero area use 3 of the given lengths. Return 
0 if impossible to return any triangle.

[\#976 Largest Perimeter Triangle](https://leetcode.com/problems/largest-perimeter-triangle/description/?envType=daily-question&envId=2025-09-28)

## Constraint
- 3 <= nums.length <= 10^4
- 1 <= nums\[i] <= 10^4

## Approach
- Sort descending
- Loop through until \(i + 1) + \(i + 2) is greater than i
- Return 0 otherwise

Runtime:
0ms beats 100%
Memory:
25.72mB beats 14.34%

## Improvements
Same logic, except doesn't init variable "end" and expand fully in if statement
