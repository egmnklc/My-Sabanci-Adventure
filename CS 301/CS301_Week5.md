---
Date: Monday 04-03-2023 | 12:51:40
Updated at: Monday 04-03-2023 | 12:51:43
---
# The Satisfiability Problem | The Problem SAT> 
> Consider a boolean formula over a set of boolean variables {x1, x2, ...., xn}


# P vs NP
> 
> $$ \normalsize \text {If a problem is in P, then the size of the solution must be bounded by a polynomial} Ο(n^k).$$
>

# NP - P
> An interesting set of problems in NP
>
> P ≠ NP
>x₀
> For an NP - Complete problem, no one was able to find a polynomial time algorithm. 
>
> The set of NP-Complete problems is growing.
>
> The problems in the class NP - Complete   have such a connection that if someone finds a polynomial time algorithm for an NP-Complete problem, then all the NP (Not only the NP-Complete problems will be solvable in polynomial time, i.e. P=NP)
>
> Also, if someone can  show than an NP-Complete problem cannot be solved in polynomial time, then P ≠ NP.

# The Second NP-Complete Problem: 3-SAT
> Since there 3-SAT is more restricted than SAT, there is a hope that it will be solvable in polynomial time. This
>
> However, 3-SAT can easily shown
...


# Clique


## Hamiltonian Circuit
> Hamiltonian Circuit is a path in a graph that visist every vertex exactly once and ends at the starting vertex.
> : The special case of a Hamiltonian Circuit is a cycle that visits every vertex exactly once. 

## Travelling Salesman
> Finding the shortest possible route that visits a set of cities and returns to the starting city. 
> : Case and goal is ending where you began, walking the minimum distance possible.
>
> TSP is an NP-hard problem, meaning that it is difficult to find an optimal solution for large distances of the problem.

# Another example for augmenting RBTs
### Now, our problem is to maintain a set of  intervals. 
> We want to support insert and delete.
> 
> ⟶ And Search an overlapping interval with a given interval.
> * For example if the selected range does not overlap any other interval, it should return null.

# Using RBTs for keeping a set of intervals
