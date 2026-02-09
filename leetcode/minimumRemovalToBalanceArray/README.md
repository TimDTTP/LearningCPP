
# Problem
Given...
    - Vector\<int>, nums
    - Int, k

Return...
    - Int

Where...
The return value is the number of removals needed to balance the array.

A balanced array means the maximum value of the array is no more than the 
minimum value times k.

[#3634 Minimum Removals to Balance Array](https://leetcode.com/problems/minimum-removals-to-balance-array/description/?envType=daily-question&envId=2026-02-06)

## Constraint
- 1 <= nums.length <= 10^5
- 1 <= nums\[i] <= 10^9
- 1 <= k <= 10^5
## Approach
Brute force
- min function to find minimum value in vector
- traverse through vector and count number of values greater than min * 2
Note: does not account removing min value

- Sort array ascending
- Iterate through vector
    - Find next value > than i * k
    - Add \(i - 1) + \(size - i - 1)
    - Hold onto value if it is new minimum
- Return min
Note: Time limit exceeded

Runtime:
14ms Beats 99.82%
Memory: 
104.92mB Beats 84.72%

## Improvements

