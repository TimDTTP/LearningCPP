
# Problem
Given...
    - Vector\<int> arr
    - Integer start

Return...
    - Boolean

Where...
you are initially positioned and index start. You can only jump to 
i +- arr\[i]. Check if you can jump to any index with value 0.

[#1306 Jump game III](https://leetcode.com/problems/jump-game-iii/description/?envType=daily-question&envId=2026-05-17)

## Constraint
- 1 <= arr.length <= 5 * 10^4
- 0 <= arr\[i] < arr.length
- 0 <= start < arr.length

## Approach
- Implement union find on arr, where all values that can traverse to each
other are connected
- pass start to union.find to check

Runtime:
0ms beats 100%
Memory:
34.93mb beats 94.42%

## Improvements

