
# Problem
Given...
    - Vector\<int>, nums
    - Int, k

Return...
    - Int

Where...
you are able to perform the following operation once per element...
- Add integer in the range \[-k, k] to the element
Return the max possible number of distinct elements in nums.

[\#3397 Maximum Number of Distinct Elements After Operations](https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/description/?envType=daily-question&envId=2025-10-18)

## Constraint
- 1 <= nums.length <= 10^5
- 1 <= nums\[i] <= 10^9
- 0 <= k <= 10^9

## Approach
- Sort array to non-decreasing order
- Track the minimum boundary
    - Either nums\[i] - k or current min from previous 
- If nums\[i] + k >= min
    - ++min and ++numOfDistinct

Runtime
112ms beats 85.80%
Memory
97.66mB beats 69.72%

## Improvements
No significant improvement without heavily sacrificing memory
