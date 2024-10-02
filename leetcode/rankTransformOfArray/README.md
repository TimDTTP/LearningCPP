
# Problem
Given...
- vector\<int>, arr

Return...
- vector\<int>

Where...
the return value is the rank of the 'int' in arr

[\#1331 Rank Transform of an Array](https://leetcode.com/problems/rank-transform-of-an-array/description/?envType=daily-question&envId=2024-10-02)

## Contraints
- 0 <= arr.length <= 10^5
- 10^-9 <= arr[\i] <= 10^9

## Approach
- Init a duplicate vector and sort
- Init map and int counter
- Iterate over sort vector and add to map, \{key : counter}
    - If duplicate value just skip
- Loop over original vector
- Match value to map key and append value pair

## Submission
Runtime 66ms Beats 69.97%
Memory 44.41 Beats 32.26%

## Online submissions
- Instead of using dedicated counter, using for loop init + increment
- Emplacing original array instead of initializing another new array for the resultant
- Using 'std::unique' to remove duplicates (minor)

