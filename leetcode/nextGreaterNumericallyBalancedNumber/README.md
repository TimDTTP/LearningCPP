
# Problem
Given...
    - Integer, n

Return...
    - Integer

Where...
integer x is numerically balanced if for every digit, d, in number x, there are 
exactly d occurences of digit d in x. Given an integer, n, return the smallest 
numerically balaced number strictly greater than n.

[\#2048 Next Greater Numerically Balanced Number](https://leetcode.com/problems/next-greater-numerically-balanced-number/description/?envType=daily-question&envId=2025-10-24)

## Constraint
- 0 <= n <= 10^6

## Approach
Depending on the number of 10's, there are a limited number of possible values
- Convert number into vector
    - temp = n % 10
    - n /= 10
- Get length of number
- Traverse and if next value is greater than len...
    - Increment current number
    - All following number = 0
    - Decrement index
- Generate vector\<map\<int, int>> of possible values and remaining frequency
- Init vector\<int> to add numbers
- Traverse through new number and for each element in vector, decrement 
frequency of next value greater or equal to number
    - Take that number at vector position and currNum * 10 + value
    - If lowerbound returns end\(), delete
- Return min

## Improvements
DNF
