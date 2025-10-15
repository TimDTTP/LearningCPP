
# Problem
Given...
    - Vector\<int>, nums

Return...
    - Int

Where...
There are 2 adjacent arrays which are strictly increasing. Where both arrays 
must be of equal length, return the maximum length of each array.

[\#3350 Adjacent Increasing Subarrays Detection II](https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/description/?envType=daily-question&envId=2025-10-15)

## Constraint
- 2 <= nums.length <= 2 * 10^5
- -10^9 <= nums\[i] <= 10^9

## Approach
- Iterate through nums
- If i > i - 1
    - increment count
- Else
    - prev = count
    - count = 1
- Conditions to check
    - If count / 2 > ans
    - If min\(count, prev) > ans

Runtime
227ms beats 56.02%
Memory 
173.75mB beats 62.03%

## Improvements

