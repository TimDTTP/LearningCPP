
# Problem
Given...
- An vector<\string>, timePoints

Return...
- A int

Where...
The return value is the minimum time difference amongst the given timePoints

[\#539 Miniumum Time Difference](https://leetcode.com/problems/minimum-time-difference/description/?envType=daily-question&envId=2024-09-16)

## Constraints
- 2 <= timePoints.length <= 2 * 10^4
- timePoints is in the format "HH:MM"

## Approach
- convert time points to full complete minute values
- 2 for nested for loops
    - one iterates for base
    - one iterates base -> end
- each loop call comparison function
- cmp function will subtract outer minutes with inner minutes, get abs()
- if value is > 720, return the value which goes around
    - 720 is max possible return value; 12 * 60
    - AKA; (24 - max) + min

