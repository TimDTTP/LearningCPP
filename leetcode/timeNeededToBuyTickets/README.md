
# Problem
Given...
1. Vector<int> tickets
2. Int k

Return...
1. Int Seconds

Where the position in the vector is the n'th person in line, and the value is the number of tickets they wish to buy.
A person can only buy 1 ticket at a time before returning to the end of the line to buy another.
Buying a ticket takes 1 second.

[\#2073 Time Needed to Buy Tickets](https://leetcode.com/problems/time-needed-to-buy-tickets/?envType=daily-question&envId=2024-04-09)

## Contraints
- 0 <= k < n
No need to check if indexing is within range
- 1 <= n <= 100
No need to check if list is empty
- 1 <= ticket[i] <= 100
No need to check if someone is in line to buy 0 tickets

## Approach
- Mathematical
1. Base value is number of tickets * number of people
2. For loop through vector
3. If number of tickets is less than target
    Subtract difference from base value
4. If number of tickets is greater than or equal to AND appears after target
    Subtract 1 from base value
