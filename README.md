## Collaborative filtering w/ divide and conquer
### Solution
given a main user and secondary user's preferences, return the number of inversions (conflicts)
conflict/inversion - ai, ak, i < k in user1, but it is ak, ai in user2



### Recurrence formula
```
T(n) = 2T(n/2) + O(n)
```

### Sources
created this on the plane so whatever i remembered from my mind
