
# Problem
Given...
- An array of integers, nums
- An integer, k

Return...
- An integer

Where the integer is the minimum number of bit flips required to be performed,
to make ALL values in nums XOR equal k

[\#2997 Minimum number of operations to make array XOR equal to k](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/description/?envType=daily-question&envId=2024-04-29)

## Constraints
- 1 <= nums.length <= 10^5
- 0 <= nums[i] <= 10^6
- 0 <= k <= 10^6

## Approach
1. Find the XOR value of all values
2. Compare bits between final and k
3. Number of differences is the answer
