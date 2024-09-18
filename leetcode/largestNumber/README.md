
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
- Iterate through nums
- Add nums to vector<\pair> 
- pair.first = string(nums)
- max size = 9
- pair.second = nums * 10^(9 - nums.size - 1)
- This is to get even base for all values to compare
- sort vector by pair.second in descending order
- iterate through vector and append string to solution
