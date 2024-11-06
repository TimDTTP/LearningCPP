
# Problem
Given...
- A vector\<int>, "nums"

Return...
- A bool

Where...
the return is whether the array is able to be sorted with the following 
condition...
- Only 2 adjacent elements are able to swap positions
- Only able to swap if the 2 numbers have the same number of set bits

[#3011 Find if Array Can Be Sorted](https://leetcode.com/problems/find-if-array-can-be-sorted/description/)

## Constraints
- 1 <= nums.length <= 100
- 1 <= nums\[i] <= 2^8

## Approach
- Track if current iteration performed any swaps
    - Default should be false
- Separate array for # of set bits for each num
- Do while \(swapped == true)
    - For int in vector
        - If int\[i] > int\[i + 1] && setBit\(num\[i]) == setBit\(num\[i + 1])
            - swap num\[i] && num\[i + 1]
            - swapped = true
- Reverse array and repeat
- If either way = sorted, return true
