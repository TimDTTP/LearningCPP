
# Problem
Given...
    - Vector\<vector\<int>> tasks

Return...
    - int

Where...
tasks\[i] is \[actual, minimum]. actual is the actual amount of energy expended 
while minimum is thes min amount of energy to start the task. Return the min 
amount of energy needed to finish all of the tasks.

[#1665 Minimum initial energy to finish tasks](https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/description/?envType=daily-question&envId=2026-05-12)

## Constraint
- 1 <= tasks.length <= 10^5
- 1 <= actual <= minimum <= 10^4

## Approach
- Sort by delta between tasks\[1] - tasks\[0]
    - Largest difference first
- Within same delta, sort by largest minimum energy first
- Then withing the same of the 2 above sort by the smallest actual energy 
expenditure first

Challenge:
How to sort the vector in the most efficient way as possible?

Runtime:
1961ms beats 5.31%
Memory: 
508.92mB beats 5.31%

## Improvements
Over-complicated the approach. The only valuable metric was the delta between
minimum and actual. The additional sorting was excessive and not needed.

