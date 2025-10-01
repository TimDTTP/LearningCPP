
# Problem
Given...
    - Int, numBottles
    - Int, numExchange

Return...
    - Int

Where...
numBottles are the number of full water bottles that you start with. numExchange
is the exchange rate of empty water bottles to 1 full water bottle. Assuming 
infinite number of exchanges, return the max number of water bottles you can 
drink.

[\#1518 Water Bottles](https://leetcode.com/problems/water-bottles/?envType=daily-question&envId=2025-10-01)

## Constraint
- 1 <= numBottles <= 100
- 2 <= numExchange <= 100

## Approach
Straight forward approach
- While loop till number of bottles >= exchange
- Divide bottles by exchange and add to total
- Add previous value to modulo as bottle in next iteration

Runtime:
0ms beats 100%
Memory:
7.90mB beats 45.09%

## Improvements

