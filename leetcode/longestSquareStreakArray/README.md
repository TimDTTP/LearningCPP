
# Problem
Given...
- An vector of ints, nums

Return...
- An int

Where...
the return value is the longest streak of values that are squared of the
previous number.

Square streak requirements...
- Minimum length of 2
- After sorting the subsequence, each subsequent value is the square of the one
before
- Return -1 if no square streak

[#2501 Longest Square Streak in an Array](https://leetcode.com/problems/longest-square-streak-in-an-array/description/?envType=daily-question&envId=2024-10-28)

## Constraints
- 2 <= nums.length <= 10^5
- 2 <= nums\[i] <= 10^5

## Approach
- add values to unordered set
- while maxCount > remaining values
- if values^2 exists; counter++


