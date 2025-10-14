
# Problem
Given...
    - Vector\<int>, nums
    - Int, k

Return...
    - Bool

Where...
the return value is if there exist 2 adjacent subarrays of length k in which
all the values are strictly increasing.

[\#3349 Adjacent Increasing Subarrays Detection I](https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/description/?envType=daily-question&envId=2025-10-14)

## Constraint
- 2 <= nums.length <= 100
- 1 < 2 * k <= nums.length
- -1000 <=nums\[i] <= 1000

## Approach
- Iterate through vector and count how many sequential increasing value
- If no longer increasing, save and compare value
- Find 2 conditions
    - If length is 2 * k
    - If prev && length are > k

Runtime:
3ms beats 99.11%
Memory:
40.49mB beats 53.98%

## Improvements
No significant improvement in logic.
Online solution is near exact same logic and beside online solution opting for a
bit more sophisticated logic instead of a if/else tree.
