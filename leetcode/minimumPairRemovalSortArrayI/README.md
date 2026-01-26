
# Problem
Given...
    - Vector\<int>, nums

Return...
    - Int

Where...
The following operation can be perform any number of times.

- Select adjacent pair with the minimum sum in nums.
    - If multiple exist, choose the leftmost one
- Replace pair with their sum

Return the minimum number of operations needed to make the array non-decreasing.

[#3507 Minimum Pair Removal to Sort Array I](https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/description/?envType=daily-question&envId=2026-01-22)

## Constraint
- 1 <= nums.length <= 50
- -1000 <= nums\[i] <= 1000

## Approach
- Initialize a vector that is the sum of each pair in order
- Fcn that returns a bool true if the nums vector is non-conforming
- While nums is non-decreasing,
    - Add min sum pair
    - Revise values in sums vector
    - Increment counter
- Return counter

Runtime
4ms beats 25.63%
Memory
28.16mB beats 15.53%

## Improvements

