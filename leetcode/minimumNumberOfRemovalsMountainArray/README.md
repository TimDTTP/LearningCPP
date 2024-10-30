
# Problem
Given...
- A vector\<int>, nums

Return...
- An integer

Where...
the return value is the minimum number of elements to remove to make "nums" a
mountain array.

Conditions to be a mountain array:
- arr.length >= 3
- Follows the following pattern
    - arr\[0] < ... < arr\[i - 1] < arr\[i]
    - arr\[i] > arr\[i + 1] > ... > arr\[arr.length - 1]
Ex. \[1, 3, 5, 4, 2] Valid
    \[2, 3, 1, 5, 2] Invalid

[#1671 Minimum Number of Removals to Make Mountain Array](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/)

## Constraints
- 3 <= nums.length <= 1000
- 1 <= nums\[i] <= 10^9
- Guaranteed to make a mountain out of "nums"

## Approach
- Traverse left to right, keeping track of number of values less than itself in order
- Traverse the opposite direction doing the same
- The index with the greatest value left + right is will be the peak
- Size - peak.left - peak.right is the minimum number of values needed to remove

