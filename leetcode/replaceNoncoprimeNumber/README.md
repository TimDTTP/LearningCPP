
# Problem
Given...
    - vector\<int>, nums

Return...
    - vector\<int>

Where...
If you find any 2 adjacent numbers in nums that are non-coprime, you delete the 
two and replace with their LCM. Repeat until there is no-longer 2 adjacent 
coprime.

[\#2197 Replace Non-Coprime Numbers in Array](https://leetcode.com/problems/replace-non-coprime-numbers-in-array/description/?envType=daily-question&envId=2025-09-16)

## Constraint
- 1 <= nums.length <= 10^5
- 1 <= nums\[i] <= 10^5

## Approach
- Iterate through nums
- Check if the nums\[i] and nums\[i + 1] are non-coprime
- If yes,
    - vector.erase\(nums.begin + \(i + 1))
    - vector\[i] = LCM
    - i--

To find LCM, use Euclid's algorithm. From there you can find GCF with the
formula LCM\(a,b) = \(a*b)/GCF\(a,b)

Runtime:
2150ms beats 5.09%
Memory:
120.97mB beats 99.07%

## Improvements
Instead of using vector::erase, prefer instantiating a different storage
instead.
Use Euclid recursively rather than multiple calls.
