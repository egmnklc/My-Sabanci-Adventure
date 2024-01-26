---
Date: Monday 04-24-2023 | 12:46:11
Updated at: Monday 04-24-2023 | 12:46:13  
---

...


## Spanning Tree
> &emsp; __Spanning tree__ of an undirected graph and connected graph G=(V,E) is a __connected acyclic subgraph__ Gₜ = (V, Eₜ) with the same vertex set V.
> : `Note that a spanning tree of a connected graph MUST be a tree.`
>

## Minimum Spannig tree of a Weighted Undirected Graph
> Givne an undirected graph G = (V,E) with a weight function
> : w: E ⟶R, let us define the weight of G, w(G) as
> $$w(G) = \sum_{u,v ∈ E} w(u, v)$$

## Finding Minimum Spanning Tree
> Note that the nodes of a MST is the same as the nodes of the original graph.
> __Invariant (Will hold throughout the execution of the program) of the algorithm is:__
> : *A* is a subset of edges of a MST  
>
> __ What is Safe Edge and definition?__
> : Say *A* is a subset of the edges of a MST, and A ∪ { (u,v) } is also a subset of the edges of a MST, and the edge(u,v) is called a `safe edge`.  
> : Safe Edge is an edge that is a part of the MST. 
>

## Prim's Algorithm for MST
> Start from a random node. Initially, only this node is said to be covered (visited).

## What can we do wen the input size is not so small?

# Heuristic (Bulgusal, keşifsel) Algorithms
> These are algorithms that do not give a guarantee of finding a correct anwer, but they work fast.
>
> We can design heuristic algorithms for hard problems, and trade optimality/correctness for speed.
>
> When we use heuristic algorithms, we cannot know how good a solution is provided by such a heuristic.
>
> On the other hand, we have Appriximation Algorithms, and provide a quality guarantee for their solutions.
>

## Approximation Algorithms
> We can try to attack these NP-complete problems with algorithms that produce *near optimal* solutions.
>
> If finding the exact solution requires exponential amount of time, then we may settle down for a solution that is not optimal, but close to the optimal solution, provided that we can produce such a result.
>

## Performance Bounds Of Approximation Algorithms
> &emsp;Suppose that our problem is an optimization problem, and let C* be the value of the optimal solution.
>
> &emsp; For a maximization problem, an approximation algorithm has a `ratio bound` p(n) for any input of size n, the algorithm produces a solution with value C and:
> : &emsp; &emsp;&emsp;&emsp;C* / C ≤ p(n) 
> : The ratio is better when it's closer to 1. Being large for this ratio is bad, and being close to 1 is good.
>
> If C* / C ≤ p(n) is satisfied, then the upper bound is p(n).
>
> &emsp; Similarly, for a minimization problem, an approximation algorithm has a *ratio bound* p(n) if for any input size n, the algorithm produces ...

## Relative Error
>|C - C*| / C* ≤ ϵ(n)

## Performance Bounds Of Approximation Algorithms
> If we can prove that a polynomial time alrorithm has a ratio bound, then we can use such an algorithm as an approximation algorithm. 
>
> Instead of spending exp amount of time to find the *exact* answer, we'll be finding a solution which is `guaranteed to be near the optimal solution` within a known factor, and we will be spending only polynomial amount of time.
>
> &emsp; However, how close we get to the optimal solution is also important now. 
>

## Approximation Scheme (We can adjust the error here)
> For NP-Complete problems, there exists approximation algorithmst hat can achieve increasingly small ratio bounds.
>
> &emsp; In other words, **giving more time** to these algorithms **produces better and better solutions**. Hence, for such algorithms there is a trade off between the computation time and the quality of the solution.
>
> An ___Approximation Scheme___ is ...
>
> If the approximation scheme uses polynomial timef or any ϵ > 0, then we call it a `polynomial time approximation scheme`
>
> An approximation scheme is a fully polynmoial approximation scheme if its running time is polynomical in 1/ϵ and n (the input size.)

## An Approximation Algorithm For Vertex Corner
> &emsp; Given a graph G=(V,E), find a minimum cardinality subset of vertices V' such that, for all edges (u,v) ∈ E, either u or is in V'.
>
> Vertex cover is an NP-hard problem (the related decision problem is NP-complete.)
>
> Hence, it is highly unlikely (not impossible because it may not be discovered yet) that we can find an optimal V' in polynomial time.
>
> `So basically our goal here is to find the minimum amount of vertexes required in order to completely cover all the vertexes in a given graph.`
> : The issue is that the algorithm picks the edges randomly.
> 


> ***STEPS***
> 1. Pick a random edge and include its vertexes, and mark their edges as covered.
> : The edges we pick here are uncovered and we're picking only one edge so there are exactly 2 vertexes. So they will ==never share a vertex.==
> 2. Repeat the first step until you visit all vertexes.
>

> C = 2 |A|, C* ≥ |A| this means 2C* ≥ 2|A|
> : and C = 2|A| ≤ 2C*, ⟶ C/C* ≤ 2.


> : A is the set of vertexes we have access to due to our edge selection.
> : 2 times the number of edges gives us the number of vertexes.

## The Meaning Of the Ratio Bound of Approx-Vertex-Cover
> We have p(n) = 2.
>
> Regardless of n, thev ertex cover set that we will find will not be larger than two times the `optimal vertex cover`.
>
> Note that p(n) is a constant and does not depend on n.

## Set Covering Problem (NP-Complete && NP-Hard Problem)
> Let F be a set of sets F = {S₁, S₂, ..., Sₙ}
>
> Let cover of F be the union of these sets in F, i.e.
> : cover(F) = S₁ ∪ S₂ ∪ ... ∪  Sₙ
>
> Find a minimal subset C of F such that,
> : cover(C) = cover(F)
>
> The decision version of the set covering problem is NP-complete.
>
> We will see an approximation algorithm for the set covering problem.

## Ratio Bound For Approx-Set-Cover
> The ratio bound for Approx-Set-Cover is:
> : p(n) = ln(n) + 1, where:
>   : n = |cover(F)|

## Fully Polynomial Approximation Scheme
> Given a set of integers X= { x₁, x₂, ..., xₙ }, find a subset X' such that the sum of the elements of X' is maximized but it is not larget than a given constant t.
>
> Approx-Subset-Sum(X, t, ϵ)
>
> It finds a solution X' such that (1-ϵ)y* ≤ y, where y& and y are the sums of the elements in X* and X'.
>
> The algorithm runs in time which is polynomial of n, t, and 1/ϵ.

# `Goal in report is to find or invent an heuristic algorithm, and analyze its resource usage as well as time.`

1. Correctness of the implementation
2. Bisi dedi de kacirdim bunu.