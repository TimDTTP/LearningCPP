
# Problem
Given...
- A vector of integers, `nums`
- An integer, `k`

Return...
- An integer

Where...
On any value in nums, you can change nums\[i] to any value between...
- nums\[i] - k 
Or
- nums\[i] + k

The 'beauty' of the array is the longest subsequence consisting of equal
elements. Note that you can only apply the operation once per index. A 
subsequence is any sequence that can be made by deleting some elements without
changing the order of the remaining elements.

[#2779 Maximum Beauty of an Array After Applying Operation](https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/description/?envType=daily-question&envId=2024-12-11)

## Constraints
- 1 <= nums.length <= 10^5
- 0 <= nums\[i], k <= 10^5

## Approach
- For num in nums\[i], increment frequency of all values from
    - nums\[i] - k to nums\[i] + k
- return max value of frequency array

Update: Approach failed due to time limit exceeded

- Sort nums
- Count number of values that satisfies the following...
    - nums\[i] + 2k >= nums\[i + x]
- Return max count

Update: Approach succeeded
Runtime: 55ms Beats 54.73%
Memory: 122.93MB Beats 39.95%
