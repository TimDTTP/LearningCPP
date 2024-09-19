
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

runtime 8ms beats 48.01%
memory 16.09mB beats 63.05%

## Online Solution
- Theory was correct, but approach was slightly inefficient
- No need to convert to ulong in order to compare a + b vs b + a
- No need to trim leading 0, if largest value was 0, return 0
