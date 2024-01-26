---
Date: Friday 04-07-2023 | 09:58:10
Updated at: Friday 04-07-2023 | 09:58:05
---

# Correctness of IntervalRBT_Search
> Case 1: Suppose at a node x, we follow the right subtree:
```c++
if ( (left[x] != NULL) and max[left[x] >= l])
    x = left[x]
else 
    x = right[x]
```
> Suppose that we follow the right subtree, but it turns out that there is no interval in the right subtree that overlaps with our interval.
> : The condition for proceeding with the right subtre:
> 1. left [ x ] == NULL
> 
> 2. max[ left [ x ]  ] < l

> Case 2: Suppose at node x, we follow the left subtree:
```C++
if (left[x] != NULL and max[left[x]] >= l)
    x = left[x]
else 
    x = right[x]
```
> Suppose we follow the left subtree, but it turns out that `there is no overlapping interval in the left subtree`. Could there be an overlapping interval in the right subtree?
> : Condition ofr following the left subtree:
>   : left[ x ] != NULL and max[ left [ x ] ]


---
# Dynamic Programming
> Dynamic programming is not an algorithm.
>
> It is a meta-technique as a guidline to design and implement new algorithms.
>
> We have seen a meta-technique called `Divide and Conquer`.
> : Basic idea was to solve the subproblems first, then combinet hense solutions to form the solution of the original problem.
>
> * If some subproblems turn out to be the same instance, then we will be solving the same problem multiple times and performing the same job multiple times.

# Typical applications for dynamic programming
> Typically applied to optimization problems.

# A guide for dynamic programing algorithms.
> Like divide and conquer algorithms, dynamic programming algorithms also have a recipe: 
> 1. Characterize the structure of an optimal solution (optimal substructure property)
> 2. Recrusively define the value of an optimal solution (requires to set up a recurrance)
> 3. Compute the value of an optimal solution in a bottom-up fashion.
> 4. If required, construct an optimal solution from the computed information.

# First example
> Suppose we have  a chain of matrices.
---