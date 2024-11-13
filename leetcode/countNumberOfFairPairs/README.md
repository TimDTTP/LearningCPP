
# Problem
Given...
- A vector of integers, "nums"
- An integer, "lower"
- An integer, "upper"

Return...
- A long long

Where...
the return value is the number of fair pairs.

A pair \(i, j) if fair if...
- 0 <= i < j < n
- lower <= nums\[i] + nums\[j] <= upper

[#2563 Count the Number of Fair Pairs](https://leetcode.com/problems/count-the-number-of-fair-pairs/description/)

## Constraints
- 1 <= nums.length <= 10^5
- nums.length == n
- -10^9 <= nums\[i] <= 10^9
- -10^9 <= lower <= upper <= 10^9

## Approach


