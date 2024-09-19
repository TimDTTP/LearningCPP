
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
- Set std::vector<std::vector<\int>>
- Set all spaces to -1
- Re-set all values based on values going down
- Traverse by column
- Find largest values and add to string
- If multiple equal, compare to adjacent right value
- If adjacent is == -1, it is higher
