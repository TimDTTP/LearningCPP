
# Problem
Given...
    - Vector\<int> nums

Return...
    - Boolean

Where...
the return value is a permutation of an array base\[n].
A base\[n] array follows the pattern...
base\[n] = \[1, 2, 3, ..., n - 1, n, n]
- Array of length n + 1
- The value n has 2 occurences

[#2784 Check if array is good](https://leetcode.com/problems/check-if-array-is-good/description/?envType=daily-question&envId=2026-05-14)

## Constraint
- 1 <= nums.length <= 100
- 1 <= num\[i] <= 200

## Approach
- get size and init vector with same size and with value 1
- vector\[n - 1] has value 2 instead of 1
- iterate through nums and check if value is still available
    - if not, return false
- at end return true

Runtime: 
0ms beats 100%
Memory: 
27.13MB beats 36.95%

## Improvements

