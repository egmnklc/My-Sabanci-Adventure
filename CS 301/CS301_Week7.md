---
Date: Monday 04-10-2023 | 12:43:53
Updated at: Monday 04-10-2023 | 12:43:57
---

# Dynamic Programming Approach to Matrix Chain Multiplication Problem
## Step 1: Characterize the structure of an optimal solution
> Suppose we know an optimal solution, and it divides the chain at index k at the top level. 
> : (A¹ × ... × Aᵏ) × (Aᵏ⁺¹ × ... × Aⁿ)
>
> In other words, it tells us to first calculate A¹..ᵏ and Aᵏ⁺¹..ⁿ,
> then multiply A¹..ᵏ and Aᵏ⁺¹..ⁿ to find A¹..ⁿ

## `So basically our goal is to find an optimal paranthesization.`

> In general. we have to make the following observation in order to be able to apply dynamic programming
>
> : **An optimal solution to the problem _contains_ optimal solution to smaller instances.**

## Step 2: Recursively define the value of an optimal solution
> Let m[i ,j] for i ≤ j, denote the minimum number of scalaer multiplications required to compute Aⁱ⁻⁻ʲ 
>
> Hence, we actually want to calculate m [1, n]
>
> We now need to define m[ i, j] recursively.
>
> Fori = j, when we have only one matrix in the chain, m[i ,j] = 0
>
> For i < j, we can define m[i, j] recursively as follows:
>
> Suppose that an optimal paranthesization splits the product after Aᵏ for some i ≤ k < j
> : Aᵗ⁻⁻ʲ = (Aⁱ × ... × Aᵏ) × (Aᵏ⁺¹ × ... × Aʲ)
>   : From `Step 1`, we know that paranthesization of the first and second components at this level must also be optimal.
>
> Hence computing Aᵗ⁻⁻ʲ in this way will require
> : m [i, k] + m[k + l, j] + pᵢ₋₋ₜ pₖ pⱼ many scalar multiplications.


> However, k can be any value between including i and excluding j.
>
> Therefore, we need to consider each k as a possible splitting point and take the minimum.

## Step 3: Compute the value of an optimal solution in a bottom up fashion.
> Having defined m[i, j] recursively, we can actually write a divide and conquer algorithm to compute m[1, n].

### `Memoization`
> `It is an optimization technique used in computer programming to speed up the execution time of a function by caching its results.`
>
> `When a function is called with a particular set of inputs, the result is stored in a cache. `
>
> `If the function is called again with the same inputs, the cached result is returned instead of recalculating the result, and this is what reduces the time and resources required to execute the function.`
>
> It is commonly used in dynamic programming, recursive algorithms, and other situtations where ___the same computation is repeated multiple times___
>

# Longest Common Subsequence Problem
> The next example on dynamic programming is LCS.
>
> Consider a sequence A = < 5, 4, 6, 3, 8, 5, 3>
>
> The length of a sequence is the number of elements in it:
> : e.g. The length of A given above is 7.
>
...

> Given two sequences A & B, a sequence C is a common subsequence of A & B, if C is a subsequence of A and C is a subsequence of B as well.
>

# Longest Common Subsequence Problem
> Suppose that we are given twi subsequences:
> : A = <a₁, a₂, ..., aₙ> 
> : B = <b₁, b₂, ..., bₙ> 
>
> and suppose that n ≤ m, if not simply interchange A & B.
>
> One may attempt to enumerate all subsequences of A,a ndf or each subsequence of A, check if that subsequence is also a subsequence of B.
>
# We need a better approach for LCS problem
> If we're trying to optimize smt, then we have an optimization problem.
>
...


# Dynamic Programming Approach for LCS
> The first step of dynamic programming wants us to `characterize the structure of an optimal solution`
>
> Consider two sequences A & B:
> : A = < a₁, a₂, ... , aₙ> 
> : B = < b₁, b₂, ... , bₙ> 
>
> and suppose that C is a longest commons ubsequence for A & B.
> : C = < c₁, c₂, ... , cₙ> 
>
> If a₁ = b₁, then c₁ must be the same as these symbols.


> For example, say
> : A = < 5, 7, 3, 8> 
> : B = <6, 5, 3, 5, 8>
>
> A LCS of A and B must end with 8.

