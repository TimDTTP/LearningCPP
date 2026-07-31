
# Problem
Given...
    - String, word

Return...
    - Integer

Where...
After remapping a traditional keypad to any distinct collections of letters
return the minimum number of pushes needed to type 'word'.

[#3016 Minimum number of pushes to type word II](https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/?envType=daily-question&envId=2026-07-31)

## Constraint
- 1 <= word.length <= 10^5
- word consist of lowercase English letters

## Approach
- Count the letters
- Populate the 2-9 from greatest to least

Runtime
43ms beats 14.55%
Memory
26.86mB beats 49.93%

## Improvements
- A more efficient way to track char freq is to index based on distance from
'a' in a set array size 26.
- For tracking the number of pushes, you can iterate normally and take...
i / 8 + 1 * freq\[i]
