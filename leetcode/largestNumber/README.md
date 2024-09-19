
# Problem
Given...
- a vector<\int>, nums

Return...
- a string

Where...
the return value is the largest value possible when nums is rearranged.

[\#179 Largest Number](https://leetcode.com/problems/largest-number/description/?envType=daily-question&envId=2024-09-18)

## Constraints
- 1 <= nums.length <= 100
- 0 <= nums[\i] <= 10^9

## Approach
- Loop through and sort values
- Sorting process
    - Try to append both values
    - Whichever is greater should be in front
- Iterate through and append to output string
