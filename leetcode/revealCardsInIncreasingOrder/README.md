
# Problem
Given...
1. A vector of int

Return...
1. A vector of int

In which the cards are pulled in increasing order in the following game.

### Game
1. Pull card from the top of deck (index 0)
2. Remove card
3. Take next top card and push it back to the bottom of the deck
Repeat till all cards are removed

[\#950 Reveal Cards in Increasing Order](https://leetcode.com/problems/reveal-cards-in-increasing-order/description/?envType=daily-question&envId=2024-04-10)

## Constraints
- All values are unique
- All values are ints
- 1 <= values <= 10^6
    int will suffice

## Approach
- Sort + reverse order
1. Sort the vector in a decreasing manner
2. Reverse the order of operations and append to vector

## Online Solutions
- Offered significant performance increase
1. Use queue structure to emulate moving values
