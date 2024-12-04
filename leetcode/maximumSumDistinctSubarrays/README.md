
# Problem
Given...
- A vector of integers, "nums"
- A integer, 'k'

Return...
- A long long

Where...
the return value is the maximum sum of a a subarray of "nums" that follows...
- Length of subarray is `k`
- All elements of subarray are distinct

If no subarray meet the requirements, return 0

[#2461 Maximum Sum of DIstinct SUbarrays With Length K](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/)

## Constraints
- 1 <= k <= nums.length <= 10^5
- 1 <= nums\[i] <= 10^5

## Approach
2 ptr system
- ptr1 at 0
- ptr2 at k
- Use set to track current values within range
- If value already existed, stop and increment to next subarray
- Compare each and track the largest sum

