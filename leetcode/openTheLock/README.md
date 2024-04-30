
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
1. Due to the large possible size of "deadends", it is best to convert it to a set for quicker lookups
2. Implement a queue for BFS
    - Queue of <string, int> tracking the combination and degree of relationship(moves)
3. Need another set to track if combo has been visited, to prevent overlap
4. While (!queue.empty()) loop to perform BFS
5. Loop through each digit of combo where each combo is incremented or decremented by 1
6. Check "new" in/decremented value against "visited" and "deadend"
7. If not either, add to queue and visited
8. Finally, if the loop manages to exit that mean there is no possible combination; return -1
