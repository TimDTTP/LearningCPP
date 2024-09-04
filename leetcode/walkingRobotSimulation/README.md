
# Problem
Given...
- A vector<int>, commands
- A vector<vector<int>>, obstacles

Return...
- An integer

Where...
The vector of commands is a series of movement commands for the robot on a 2D 
plane. There may or may not be an obstacle on the plane, which if blocked, will 
stay in place and proceed to the next command.

Return the max Euclidean distance from the origin, (0, 0), squared.
ie. (5, 6) -> 5^2 + 6^2 -> 61

If command = -1; turn right 90 degrees
If command = -2; turn left 90 degrees

[\#874 Walking Robot Simulation](https://leetcode.com/problems/walking-robot-simulation/description/?envType=daily-question&envId=2024-09-04)

## Constraints
- Obstacles can be at 0,0
- 1 <= command.length <= 10^4
- commands[\i] can be either -1, -2 or a value [\1, 9]
- 0 <= obstacles.length <= 10^4
- -3 * 10^4 <= x,y <= 3 * 10^4
- Answer guaranteed to be less than 2^31
    - Thus fits within an int

## Approach
- Starting from 0,0
- Init direction function that cycles through the possible directions to head in
- Iterate through commands
    - if change direction, function call direction function
    - if 1-9, call walking function

- Direction function
    - If -1, increment array + 1
    - If -2, decrement array - 1
    - If out of bounds, return to other end

- Walking function
    - Given a number and direction
    - If north increment y
    - If eash increment x
    - If south decrement y
    - If west decrement x

- Obstacle handling function
    - WIP
