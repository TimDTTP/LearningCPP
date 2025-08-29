
# Problem
Given...
    - An int, n
    - An int, m

Return...
    - A long long

Where...
    - The return value is the number of possibilities of Alice winning.
    - Alice will always go first
    - The game is set up by 2 rows of flowers
    - The number of flowers in the first row is in the range \[1,n]
    - The number of flowers in the second row is in the range \[1,m]
    - Each turn the player must choose a lane and pick a flower
    - At the end of the turn, if there are no flowers left, the current player 
captures the opponent and wins

[\#3021 Alice and Bob Playing Flower Game](https://leetcode.com/problems/alice-and-bob-playing-flower-game/description/?envType=daily-question&envId=2025-08-29)

## Constraint
- 1 <= n, m <= 10^5

## Approach
- Looks like just the only win condition is an odd number of flowers
- Multiply number of odd numbers of n with number of even numbers of m
- Multiply number of even numbers of n with number of odd numbers of m
- Add those two numbers up and return

Runtime
0ms beats 100%

Memory 
8.51mB beats 12.44%

## Improvements
- Could simplify down further to "m * n / 2"
