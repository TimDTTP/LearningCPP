
# Problem
Given...
    - Vector\<int>, arr

Return...
    - Vector\<vector\<int>> 

Where...
Arr is an array of distinct values, return a list of all the pairs in ascending order 
which have the overall minimum absolute difference of any 2 elements.
The first value of the pair will be the lesser of the two values.

[#1200 Minimum Absolute Difference](https://leetcode.com/problems/minimum-absolute-difference/description/?envType=daily-question&envId=2026-01-26)

## Constraint
- 2 <= arr.length <= 10^5
- -10^6 <= arr\[i] <= 10^6

## Approach
- Sort vector
- Iterate through
    - Track lowest difference and their index
- Using all indexes of the lowest value, assemble pair list 
    - This should be the value at said index + the next value

Runtime
15ms Beats 76.40%
Memory
36.88mB Beats 16.96%

## Improvements

