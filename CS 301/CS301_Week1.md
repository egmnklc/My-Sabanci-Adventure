---
Date: Friday 03-03-2023 | 09:46:07
---

---
# Algorithm Design Techniques
---
# Divide and Conquer
Another such design approach. Divide and Conquer algoithms are recursive in their nature. Relatively easy to state their running time by using recurannce.

## Three steps of Divide and Conquer
1. Divide: The problem is divided into several smaller subproblems/intances. 
2. Conquer: Subproblems are atacked by the same algorithm. When subproblems are small enough, problem is solved staright.
3. Combine: As recursions come back, solutions to the subproblems comined to form the solution of the original problem.

### Merge Sort
> Given two sorted sequences, [a₁, a₂, ..., aₙ] and [b₁, b₂, ..., bₙ] these two can be merged efficiently into a single sorted sequence.
>> 1. Divide: Divide n element squeence into n/2 elemented sequences.
>> 2. Conquer: Sort subsequences recursively with merge sort. Recursion will end when we have single element lists.
>> 3. Combine: Merge sorted subsequences using merge operation above.
>
> Execution of Merge Sort
>
> : [3 8 4 1]
> 
> : [3 8] | [4 1]
> 
> : [ 3 ] | [ 8 ] | [ 4 ] | [ 1 ]
>
> : [ 3 8 ] | [1 4]
> 
> : [1 3 4 8]

```C++
MergeSort(A, p, r){ 
    if (p < r){
        q = floor((p+r)/2);
        MergeSort(A, p, q); // Here
        MergeSort(A, p+1, q); // And here are the conquer steps, each takes T(n/2) time.
        Merge(A, p, q, r); // Merge step is here. Combine step will take linear time.
    }
}
// P and R are pointers. If P and R are the same, then we have one element and code goes into the else part.
```

# Analysis of Divide and Conquer Algorithms
> If an algorithm is recursive, its running time can be described by a ==recurrance relation==.
>
> A recurrance for runing time T(*n*) of a DAQ is based on three steps of the design approach.
>
> : Suppose n sized problem divided into a subproblems with size n/b. Suppose dividing takes D(*n*) time.
> : When problem size gets small enough, (*say smaller than a constant c*), we apply a straightforward technique to solve the problem in a constant amount of time Θ(1).
> : ==If the size is constant, then the time needed is also constant.==
> : Suppose combining the solutions takes C(*n*) time.
> The recurrance fr a divide and conquer algorithm will be:
> > T(*n*) = { θ(1), if n < c
> > a×T(n/b)+D(n)+C(n), otherwise
> >
> > a(*# of subproblems we create*) × T(*n/b*)(* of each subproblem*)+*D*(*n*)+*C*(*n*), otherwise }
# Analysis of Merge Sort
> 2×T(n/2)+θ(1)+θ(n) => θ(n × logn)

# Comparison of Insertion Sort and Merge Sort
> Inseriton Sort: θ(n²)
> 
> Merge Sort: θ(nlog₂n), asymptotacilly more efficient than Insertion Sort.
>
> > Due to constant coefficients, Inseriton Sort may be preferable for small input sizes. Insertion Sort has good performance on almost sorted inputs.

# Growth of Functions
> Order of growth of running time / resource usage provides:
> 1. Simple characterization of an algorithm's efficiency.
> 2. A tool to compare the relative asymptotic performances of algorithms.
> 
> Exact running time can sometimes be derieved, but its use is limited and not worth the effort computing it when input gets large. Lower order terms and constant coeeficients are all dominated by the ???????

# Asymptotic Notation
> Asymptotic running time of algorithms using a function *T*(*n*) with domain set of Natural Numbers *N* = {0, 1, 2, ...}

# Ο-notation (upper bounds)
> *f*(*n*) = Ο(*g*(*n*)) if there exists positive constants c and n₀ such that
> : → ∀ n ≥ n₀, 0 ≤ *f*(*n*) ≤ *cg(*n*)*
>
> For example, 2n² = O(n³) [ take c=1, n₀2]
> 
> g(n) bounds f(n) from above.
> The rate of growth of f(n) is at most the same as the rate of growth of g(n).
> 
> Note that for asymptotic notations, = is a funny, one way equality. 


