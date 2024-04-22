
# Problem
Given...
- A vector of string "deadends", where if at any point the code displays these
    number the lock will be unable to proceed turning
- A string "target", where it is the desired code combination

Return...
- An integer indicating the minimum amount of turns to get to the "target", return -1
    if impossible

Where...
The lock is in the form of 4 wheels, displaying values from '0' to '9'. The wheels can
spin freely from '0' to '9' in one turn.

[\#752 Open the lock](https://leetcode.com/problems/open-the-lock/description/?envType=daily-question&envId=2024-04-22)

## Constraints
- 1 <= deadends.length() <= 500
- Target will NOT be in deadends
- Target and deadends will ONLY contain digits

## Approach
- BFS
1. For each 4 digit combo, perform BFS on increment AND decrement on each digit
2. If value is in deadend, pop()
3. If value is the target, return iteration
4. Else push value into queue.
