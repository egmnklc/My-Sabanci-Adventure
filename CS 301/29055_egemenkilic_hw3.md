---
Date: Tuesday 04-25-2023 | 12:22:28
Updated at: Tuesday 04-25-2023 | 12:22:30
---

# Question 1 [40 points]
## A palindrome is a sequence of characters that reads the same backward as forward. In other words, if you reverse the sequence, you get the same sequence. For example, “a”, “bb”, “aba”, “ababa”, “aabbaa” are palindromes. We also have real words which are palindromes, like “noon”, “level”, “rotator”, etc. We also have considered the concept of a subsequence in our lectures. Given a word A, B is a subsequence of A, if B is obtained from A by deleting some symbols in A. For example, the following are some of the subsequences of the sequence “abbdcacdb”: “da”, “bcd”, “abba”, “abcd”, “bcacb”, “bbccdb”, etc. The Longest Palindromic Subsequence (LPS) problem is finding the longest subsequences of a string that is also a palindrome. For example, for the sequence “abbdcacdb”, the longest palindromic subsequence is “bdcacdb”, which has length 7. There is no subsequence of “abbdcacdb” of length 8 which is a palindrome. One can find the length of LPS of a given sequence by using dynamic programming. As common in dynamic programming, the solution is based on a recurrence. Given a sequence A = a1a2 . . . an, let A[i, j] denote the sequence aiai+1 . . . aj .  Hence it is part of the sequence that starts with ai and ends with aj (including these symbols). For example, if A = abcdef, A[2, 4] = bcd, A[1, 5] = abcde, A[3, 4] = cd, etc. For a sequence A = a1a2 . . . an, let us use the function L[i, j] to denote the length of the longest palindromic subsequence in A[i, j].

### a.  [10 points] If we have a sequence A = a1a2 . . . an, for which values of i and j, L[i, j] would refer to the length of the longest palindromic subsequence in A?

> Since `L` already returns the longest palindromic subsequence, all we need to do is to feed the `L` function with a whole subsequence, and it will return the length of the longest palindromic subsequence.
> : Therefore, values for i and j in L[i, j] when working with a sequence with the definition A = [aᵢ, aᵢ₊₁, ... , aⱼ]:
>   : Values in i and j for L[i, j] would be i=1 and j=n s.t. 
> L[1, n]

### b. [20 points] Write the recurrence for L[i, j].
$$
L[i ,j]=
\begin{cases}
0  & \quad \text{if i > j}\\ 
1  & \quad \text{i = j}\\
L[i+1, j-1] + 2  & \quad \text{i = j and aᵢ = aⱼ}\\
max(L[i+1, j], L[i, j-1])  & \quad \text{i = j and aᵢ != aⱼ}
\end{cases}
$$ 

### c. [10 points] What would be the worst case time complexity of the algorithm in Θ notation? Why?
> The worst case in here would be Θ(n²). At the class, and back in CS300, we created a matrix table of n×n size in order to store the length of the longest subsequence. Since we need to look at all the elements in the table in order to find which value is the maximum, we need to look at a total of n² elements. Hence the worst time complexity of this algorithm would be Θ(n²).

## Question 2
### Consider the 0–1 knapsack problem, where we have a set of n objects (o1, o2, . . . , on), each with a weight (w1, w2, . . . , wn) and a value (v1, v2, . . . , vn). Here, the object oi has the weight wi and the value vi . Suppose that W is the capacity of our knapsack. We would like to compute the maximum value that we can pack into our backpack. Let P[i, j] denote the maximum value that can be packed into a knapsack with capacity j, if we consider only the first i objects, i.e. o1, o2, . . . , oi.

### a.  [10 points] For which values of i and j, P[i, j] would refer to the maximum value that can be packed into our knapsack of capacity W if we consider all n items?

> We need to calculate the max value of the objects, while considering if their total capacity is less than or equal to W. It is given that we have n objects. 
> : So for i, we can write i=n, it will denote the first n objects. 
>
> For first n objects, we need to calculate their capacities so that they will fit into our knapsack.
> : So for j, we can write j=W, since W is our capacity, and:
>   : ⟶ `P[n, W]` will return us the maximum value that can be packed into our knapsack of capacity W when we consider n items. 
### b.  [20 points] Write the recurrence for P[i, j].
$$
P[i ,j]=
\begin{cases}
0 & \quad \text{if i = 0}\\ 
P[i-1, j] + vᵢ & \quad \text{i > 0 and j < wᵢ}\\
P[i-1, j-w] + vᵢ & \quad \text{i > 0 and j ≥ wᵢ}\\
\end{cases}
$$ 

### c.  [10 points] What would be the worst case time complexity of the algorithm in Θ notation? Why?
> For the worst case, we need to have a look at all the combinations we can produce. Hence, we need to create a DP table with size n × W, where n is the number of objects and W is the maximum capacity of our knapsack. While filling the table, we will update its values if we can fit in the current element, or replace it with another element(s) if available. 
> : As a result, we will have a total number of nW elements, so:
>   : The time worst time complexity will be of Θ(nW) time.

## Question 3 
### Consider again the 0–1 Knapsack problem. This time, instead of developing a dynamic programming solution, we would like to suggest a greedy solution. If we have a set of n objects (o1, o2, . . . , on), each with a weight (w1, w2, . . . , wn) and a value (v1, v2, . . . , vn), and if we have a capacity W:
### a. (a) [10 points] What would be a greedy choice to pick the object to be included in our knapsack at this point?
> Picking an element highest value regardless from their weights at each step would be a greedy choice (it will not always produce the optimal solution). 
>
### (b) [10 points] If we pick the object oi by the greedy choice in part (a), what would be the subproblem that we will be left with, after this choice of object?
> We may have the highest value in the knapsack but we don't perform any checks if the total weight could be carried by the knapsack. Therefore, total weight vs max capacity comparsion will be a subproblem.
> 