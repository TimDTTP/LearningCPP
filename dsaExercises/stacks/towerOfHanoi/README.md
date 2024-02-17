
# Problem

Create a program to solve the mathematical problem "Tower of Hanoi"

[Link:](https://www.geeksforgeeks.org/iterative-tower-of-hanoi/)

## Approach
1. Calculate the number of moves ((2^n) - 1)
2. For each iteration, i...
    - if i % 3 == 2
        - Interchange top of S and A pole, whichever is less than
    - if i % 3 == 1
        - Interchange top of S and D pole, whichever is less than
    - if i % 3 == 0
        - Interchange top of A and D pole, whichever is less than
