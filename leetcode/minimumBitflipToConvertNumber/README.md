
# Problem
Given...
- int, start
- int, goal

Return...
- int

Where...
The return value is the number of bits needed to be flipped in order for start
    to equal goal.

[\#2220. Minimum Bit Flips To Convert Number](https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/?envType=daily-question&envId=2024-09-11)

## Constraints
- 0 <= start, goal <= 10^9

## Approach
- Convert start and goal to bits using 'bitset'
- Strip to length of goal
- Count number of differences using loop

runtime 0ms beats 100%
memory 7.46mB beats 92.77%

## Online Solution
- Instead of using for loop, using XOR would've been more coherent
