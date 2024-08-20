
# Problem
Given...
A vector of ints; bills

Return...
A bool

Where...
The every order in line are able to be returned the exact change.

[\#860 Lemonade Change](https://leetcode.com/problems/lemonade-change/description/?envType=daily-question&envId=2024-08-15)

## Constraints
- 1 <= bills.length <= 10^5
- bills[i] can only be 5, 10, or 20

## Personal notes
- When encountering $20, causes a split in possibilities of using...
    - $10 + $5
    - $5 + $5 + $5

## Approaches
- Dicts
 1. Iterate through vector
 2. Check if proper change is available
 3. If 20, split possibilities
    - Attempt to use 10 + 5 first
    - If failed...
        - Flip bool
        - Exit
 4. If possible add bill to dict
 5. At the end return bool toggle
