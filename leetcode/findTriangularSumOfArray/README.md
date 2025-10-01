
# Problem
Given...
    - Vector\<int>, nums

Return...
    - Int

Where...
For each index, i, assign the new value to be \(nums\[i] + nums\[i + 1]) % 10. 
At the end, there should be 1 less than what we started with. Continue until 
there is only 1 elements left.

[\#2221 Find Triangular Sum of an Array](https://leetcode.com/problems/find-triangular-sum-of-an-array/description/?envType=daily-question&envId=2025-09-30)

## Constraint
- 1 <= nums.length <= 1000
- 0 <= nums\[i] <= 9

## Approach
Brute force
- While array is != 1
- Combine values down up to n - 1
- Return

Runtime: 
41ms beats 97.19%
Memory:
22.26mB beats 88.70%

## Improvements

