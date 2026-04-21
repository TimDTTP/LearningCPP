
# Problem
Given...
    - vector\<int> source
    - vector\<int> target
    - vector\<vector\<int>> allowedSwaps

Return...
    - int

Where...
Vector target\[i] will contain indexes of \{a, b} which are the indices of 
source/target that are allowed to be swapped. Return the minimum hamming 
distance. 

Hamming distance is the number of elements that are different that share the 
same indices.

[#1722 Minimize Hamming Distance After Swap Operations](https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/description/?envType=daily-question&envId=2026-04-21)

## Constraint
- n == source.length == target.length
- 1 <= n <= 10^5
- 1 <= source\[i], target\[i] <= 10^5
- 0 <= allowedSwaps.length <= 10^5
- allowedSwaps\[i].length == 2
- 0 <= a, b <= n - 1
- a != b

## Approach
-

## Improvements

