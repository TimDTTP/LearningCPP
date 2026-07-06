
# Problem
Given...
    - Vector\<vector\<int>> intervals

Return...
    - Integer

Where...
After removing "covered" intervals, return the remaining number of intervals.

Interval \[a, b] is covered by \[c, d] if the following
this pattern is present...

c <= a and b <= d

[#1288 remove covered intervals](https://leetcode.com/problems/remove-covered-intervals/description/?envType=daily-question&envId=2026-07-06)

## Constraint
- 1 <= intervals.length <= 1000
- intervals\[i].length == 2
- 0 <= l < r <= 10^5
- All the given intervals are unique

## Approach
- Sort intervals ascending order by first index
- Iterate through and track...
    - Max value in second index
    - Number of value which are lower than current max value

Runtime:
0ms beats 100%
Memory:
15.22mb beats 30.60%

## Improvements

