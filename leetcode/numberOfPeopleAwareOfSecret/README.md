
# Problem
Given...
    - int, n
    - int, delay
    - int, forget

Return...
    - int

Where...
starting with one person with the secret, they can start sharing the secret 
to one more person each day after \{delay} days of discovering the secret. 
However, each person will forget the secret after \{forget} days after 
discovering it. Given \{n} days, return the number of people aware of the 
secret at the end of \{n} days. A person cannot share the secret on the same 
day of forgetting.
Since the answer can be very large, return it modulo 10^9 + 7

[\#2327 Number of People Aware of a Secret](https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/?envType=daily-question&envId=2025-09-09)

## Constraint
- 2 <= n <= 1000
- 1 <= delay < forget <= n

## Approach
- A vector\<pair\<int, int>> size == forget 
- For loop n
    - Iterate through and count number of vector\[i].first >= delay 
    count += vector\[i].second
    - Also increment vector\[i].first
        - If vector\[i].first == forget; erase
    - If count != 0; vector.push_back\({1, count})
- Accumulate vector\[i].second

## Improvements

