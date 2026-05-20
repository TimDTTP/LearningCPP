
# Problem
Given...
    - Vector\<int> A
    - Vector\<int> B

Return...
    - Vector\<int>

Where...
The return value is a prefix common array of A and B such that C\[i] is equal 
to the count of numbers that are common in both A and B that are present at AND
before the index i.

[#2657 Find the prefix common array of two arrays](https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/?envType=daily-question&envId=2026-05-20)

## Constraint
- 1 <= A.length == B.length == n <= 50
- 1 <= A\[i], B\[i] <= n
- It is guarateed that A and B are both a permutation of n integers

## Approach
- B into a unordered map
- Iterate through A and find the match
- C\[max\(i, map\[A\[i]])]++
- Loop over C once more and add previous values

Runtime:
8ms beats 47.28%
Memory:
88.18mB 36.61%

## Improvements
- Using a frequency table to track the occurence of a value
- Overall more elegant due to being a 1 pass algorithm

Personal approach
O\(J + 3N)
- J is extra objects needed
- 3N due to have to loop over 3 times

Online approach
O\(N)
