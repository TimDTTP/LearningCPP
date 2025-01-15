
# Problem
Given...
- An integer, num1
- An integer, num2

Return...
- An integer

Where...
1. The value has the same number of set bits as num2
2. The value XOR num1 is minimal

[#2429 Minimize XOR](https://leetcode.com/problems/minimize-xor/description/)

## Constraints
- 1 <= num1, num2 <= 10^9

## Approach
1. Count number of set bits of num2
2. Convert num1 to bits
3. From left to right, if num1 is a set bit, set the bit on temp value and
decrement counter
4. If the end is hit and counter is greater than 0, go backwards and set bits 
and decrement counter
5. Convert temp value to integer and return
