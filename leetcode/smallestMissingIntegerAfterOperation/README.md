
# Problem
Given...
    - Vector\<int>, nums
    - Int, values

Return...
    - Int

Where...
you can add or subtract value to any element in nums any number of times. The
MEX \(minimum excluded) of an array is the smallest missing non-negative integer
in it. Return the maximum MEX of nums after applying the operation any number
of times.

[\#2598 Smallest Missing Non-negative Integer After Operations](https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/description/?envType=daily-question&envId=2025-10-16)

## Constraint
- 1 <= nums.length, value <= 10^5
- -10^9 <= nums\[i] <= 10^9

## Approach
- Iterate through nums and increment nums\[i] % values in map
- If nums\[i] is negative, multiply til positive, then perform modulo in map
- Iterate 0 -> values and decrement count in map, first to fail is max MEX

Runtime:
68ms beats 38.38%
Memory:
135.86mB beats 19.70%

## Improvements

