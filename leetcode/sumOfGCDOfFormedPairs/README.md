
# Problem
Given...
    - Vector\<int> nums

Return...
    - Long long

Where...
1. Construct a max array where mx\[i] = max\(nums\[0], nums\[1], ..., nums\[i]) 
2. Construct a prefixGcd array where prefixGcd\[i] = gcd\(nums\[i], mx\[i])
3. Sort prefixGcd in non-decreasing order
4. Form pairs by matching the smallest unpaired value to the largest 
unpaired value. Repeat till no more pairs can be made
    - If n is odd, ignore the middle value of prefixGcd
5. Return an integer denoting the sum of the GCD of values of all formed pairs

[#3867 Sum of GCD of formed pairs](https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/description/?envType=daily-question&envId=2026-07-16)

## Constraint
- 1 <= n == nums.length <= 10^5
- 1 <= nums\[i] <= 10^9

## Approach
-

## Improvements

