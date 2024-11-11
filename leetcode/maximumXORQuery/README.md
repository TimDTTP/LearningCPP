
# Problem
Given...
- A vector of integers, "nums"
- An integer, "maximumBit"

Return...
- A vector of integers

Where...
the return vector is the following n times query:
- A non-negative integer where k < 2^maximumBit
- Where nums\[0] XOR ... XOR nums\[nums.length - 1] XOR k is maximized
- Remove last element of current array nums

[#1829 Maximum XOR for Each Query](https://leetcode.com/problems/maximum-xor-for-each-query/description/)

## Constraints
- nums.length == n
- 1 <= n <= 10^5
- 1 <= maximumBit <= 20
- 0 <= nums\[i] < 2^maximumBit
- nums is sorted in ascending order

## Approach
- Iterate over nums
- Get XOR of current value and previous
- Take first "maximumBit"s and flip bit 
- Replace current index with new value
- Return nums.reverse

Runtime 10ms Beats 20.56%
Memory 95.38mB Beats 88.70%
