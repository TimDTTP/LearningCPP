
# Problem
Given...
- A vector of integers, differences
- An integer, lower
- An integer, upper

Return...
- An integer

Where...
Differences is a vector of size n - 1. Where difference\[i] is the difference 
of a hidden sequence of numbers where hidden\[i + 1] - hidden \[i]. Lower and 
upper are the bounds of the possible values that hidden\[i] can possibly be. 
Return the number of possible hidden sequence that can exist. If no possible 
sequence, return 0.

[#2145 Count the hidden sequences](https://leetcode.com/problems/count-the-hidden-sequences/description/?envType=daily-question&envId=2025-04-21)

## Constraint
- n == differences.length
- 1 <= n <= 10^5
- -10^5 <= differences\[i] <= 10^5
- -10^5 <= lower <= upper <= 10^5

## Approach
- Essentially a sliding window
- Find upper and lower extremes after performing all operations in 
differences
- Return the delta between bounds and difference's extremes
- If extremes is greater than bounds, this means there are no possible 
sequences

Runtime:
0ms | Beats: 100%
Memory:
112.45mB | Beats: 97.58%
