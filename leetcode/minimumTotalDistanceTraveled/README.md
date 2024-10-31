
# Problem
Given...
- A vector\<int>, robot
- A vector\<vector\<int>>, factory

Return...
- A long long

Where...
the return value is the minimum distanced needed for all robots to be fixed at
the factories.
- Each robot can only move in either the positive or negative x direction
- All robots are initially broken

[#2463 Minimum Total Distance Traveled](https://leetcode.com/problems/minimum-total-distance-traveled/description/)

## Constraints
- All positions of robots are unique
- All positions of factories are unique
- All robots move at the same speed
- All test cases will have all robots able to be repaired
- Moving robots will never collide
- If a robot passes a factory that has reached its limit, it will cross it
- 1 <= robot.length, factory.length <= 100
- factoy\[j].length == 2
-  -10^9 <= robot\[i], position <= 10^9
- 0 <= limit <= robot.length

## Approach
