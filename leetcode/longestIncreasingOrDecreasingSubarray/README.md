
# Problem
Given...
- A vector of integers, nums

Return...
- A integer

Where...
The return value is the longest subarray which the values are strictly 
increasing or decreasing

[#3105 Longest strictly increasing or strictly decreasing subarray](https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/?envType=daily-question&envId=2025-02-03)

## Constraints
- 1 <= nums.length <= 50
- 1 <= nums\[i] <= 50

## Approach
- Iterate over vector
- If counter > 1
    - if i < i + 1 == bool
        - ++counter
    - else
        - max\(curr, new)
        - counter = 1
- If counter == 1
    - bool = i < i + 1
    - ++counter
- Return max value found

Time complexity: O\(n)

Runtime: 0ms Beats 100%
Memory: 27.97mB Beats 27.06%
