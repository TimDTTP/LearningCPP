
# Problem
Given...
    - A vector\<int>

Return...
    - A int

Where...
the return value is the number of elements with the max frequency. AKA elements 
with the same frequency of the max frequency. 

[\#3005 Count Elements With Maximum Frequency](https://leetcode.com/problems/count-elements-with-maximum-frequency/description/?envType=daily-question&envId=2025-09-22)

## Constraint
- 1 <= nums.length <= 100
- 1 <= nums\[i] <= 100

## Approach
- Store element frequency in a unordered_map
- If frequency \> current max, max = new element
    - Count = 1
- Else if map\[i] = max
    - count++
- Return count


## Improvements


