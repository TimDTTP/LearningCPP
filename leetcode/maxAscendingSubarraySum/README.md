
# Problem
Given...
- A vector of integers, nums

Return...
- A integer

Where...
The return value is the maximum possible sum of an ascending subarray in nums.

[#1800 Maximum ascending subarray sum](https://leetcode.com/problems/maximum-ascending-subarray-sum/description/)

## Constraints
- 1 <= nums.length <= 100
- 1 <= nums\[i] <= 100

## Approach
- Set a maxTracker to track the max sum so far and currSum to track sum
- Set initial value of currSum to i\[0]
- Iterate through nums
- If nums\[i] < nums\[i + 1]
    - Add nums\[i + 1] to currSum
- Else
    - Compare maxTracker and currSum
    - Reset currSum to nums\[i + 1]
- Once the loop has finished running, perform a final compare in the event
that there is a subarray that is ascending through the last position
- Return maxTracker

### Analysis
This approach should result in a time complexity of O\(n) because it should
only pass through the size of the input once.

Space wise, this should be O\(1) because we are not dedicating any space that
will accomodate and change to the size of the input. Only the use of 2 int
variables.

Results:
Runtime
0ms Beats 100%

Memory
11.23mB Beats 12.08%

