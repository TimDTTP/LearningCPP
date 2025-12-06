
# Problem
Given...
    - Vector\<int>, nums
    - Integer, k

Return...
    - Integer

Where...
The task is to return the total number of ways to partition nums in which...
- Each contiguous segment's maximum and minimum difference elements is at most k
Return the solution in modulo 10^9 + 7

[#3578 Count Partitions With Max-Min Difference at Most K](https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/description/?envType=daily-question&envId=2025-12-06)

## Constraint
- 2 <= nums.length <= 5 * 10^4
- 1 <= nums\[i] <= 10^9
- 0 <= k <= 10^9

## Approach
Recursion
- Push first value into recursive function
- If current index is last, increment count
- Recursive call to next value
- Check if next value will fulfill condition, if true recursive call to next 
value

## Improvements

