---
title: CS310 Second Week
Date: Monday 03-06-2023 | 12:37:43
Updated at: Monday 03-06-2023 | 12:37:46
---

# *Ο-notation (Upper Bounds)
> f(n) = O(g(n)) if there exists positive constants c and n₀ such that, ==∀ n ≥ n₀, 0 ≤ f(n) ≤ cg(n)==.
> : For example 2n² = O(n³) [take c=1, n₀=2]
> 
> * g(n) bounds f(n) from above.
> * Rate of growth of f(n) is at most the same as the rate of growth of g(n).
> 
> Note that = is a funny one way equality.
>
# Formal Definition of Ο-notation
> O(g(n)) =  
> &emsp; &emsp; &emsp; f(n): ∃c, n₀ > 0 such that ∀ n≥n₀, 0≤f(n)≤cg(n) 
>   
> * Therefore, O(g(n)) denotes a set of functions.
>

# Ο-notation on expressions
> * n=O(n), it means n ∈ O(n).
> 
>   * 2n² + 7n + 2 = 2n² + O(n) means:
> 
>   * &nbsp; &nbsp; COMPLETE HERE
>
> * In relational expressions as well:
```
T(n) ≥ O(n²) means:
    → ∃ f(n) ∈ O(n²)
```
> ## !!! ==Little o-notation is used to give upper bounds that are not tight!==
> * We use little o to distingush between tight and loose bounds.
> 
> * 5n²= O (n²) → tight upper bound
> * 3n = O(n²) → loose upper bound

# Formal Definiton of o-notation
> ## Definition of Ο-notation 
> O(g(n)) = f(n): ∃c, n₀ > 0, such that ∀ n≥ n₀, 0≤f(n)≤cg(n)
>
> ## Definition of ο-notation
```c++
ο(g(n)) = f(n): 
∀c > 0, ∃n₀ > 0 such that ∀n≥n₀, 0 ≤ f(n)≤ cg(n)

ο(g(n)) = f(n):  
∀c > 0, ∃n₀ > 0 such that ∀n≥n₀, 0 ≤ cf(n)≤ g(n)
```
### Examples for ο-notation
> 3n=o(n²)
>
> 3n < cn² `[need to show how to pick n₀ for any given c]`
>

# Ω-notation (Lower Bounds)
> Ω-notation provides asymptotic lower bounds.
>
```C++
f(n) = Ω(g(n)) if there exist positive constatns c and n₀ such that, ∀ n≥n₀, o ≤ cg(n)≤ f(n).

```
## Ω-notation provides a lower bound
> If the best case running time of an algorithm is Ω(g(n)), then any running time of the algorithm is also Ω(g(n)).


# ω-notation (Lower Bounds That Are Not Tight)
> Bounds given by Ω-notation may or may not me tight:
>   > 5n² = Ω(n²)
>   > 5n² = Ω(n)
> 
> ω-notation provides lower bounds that are not tight.
> When f(n) = ω(g(n)), g(n) bounds f(n) from COMPLEtE HERE.
>
## Formal Definition of ω-notation
```c++
One way of defining is to say:
    f(n) = ω(g(n)) ⟺ g(n) = o(f(n))
```
> f is strictly faster growing compared to g.
> > If g(n) is slower growing compared to f, then f is strictly faster growing compared to g.
>
> Set notation:
> ``` ω(g(n)) = f(n) : ∀c>0, ∃n₀ > 0 such that ∀ ≥ n₀ COMPLETE HERE ```

# Θ-notation (Tight Bonuds)
```
Θ(g(n)) = f(n):
    ∃c₁, c₂, n₀ > 0 such that ∀ n≥n₀, 0≤c₁g(n)≤ f(n) ≤ c₂g(n) 
```

# Some pooperties of asymptotic notations
```
Ω ⟶ Lower Bound
Ο ⟶ Upper Bound

f(n) = Θ(g(n)) ⟺ f(n) = O(g(n)) ∧ f(n) = Ω(g(n))
    Rate of growth of f and g are the same.

f(n) = Θ(g(n)) ⟺ g(n) = Θ(f(n))

f(n) = O(g(n)) ⟺ g(n) = Ω(f(n))

f(n) = o(g(n)) ⟺ g(n) = ω(f(n))

f(n) = Θ(f(n)) COMPLETE HERE

f(n) = Θ(g(n)) ∧ g(n) = Θ(h(n)) ⟹ f(n) = Θ(h(n))
    This still holds when Θ is replaced by any other asymptotic notation we introduced (O, Θ, o, ω)

```

## Not all functions are compralbe
> Consider f(n)=n and g(n)=n⁽¹⁺ˢⁱⁿ⁽ⁿ⁾⁾
> : → f(n) and g(n) cannot be compared.
> > * g is an oscillating function. 
> > : It will go below and above f(n) so we can't strictly state that g(n) is slower of faster than f(n).

# Some Complexity Classes
> Θ(1): constant

> Θ(logn): logarithmic

> Θ(n): linear

> Θ(nlogn): loglinear, linearithmic

> Θ(n²): quadratic

> Θ(n³): cubic

> Θ(nⁿ): exponential

---
# Recurrances
A recurrance is ane quaiton or inequality that describes a function in temrs of itself, (usually on its values on smaller inputs.) {: #note}

# Recursive and Recursion Free Expressions
> It cna be very easy to write down the running time a recursive algorithm by using a recurrance.
```c++
Merge-Sort(A,p,r){
    if (p < r) {
        q = floor((p+r)/2);
        Merge-Sort(A,p,q);
        Merge-Sort(A,q+1,r);
        Merge(A,p,q,r);
    }
}

Running time T(n) = 

                Θ(1)          , if n = 1
                2T(n/2) + Θ(n), otherwise

                vs.

                T(n) = Θ(nlogn)
```

> Solving a recurrance means finding a recursion-free solution.
>
> For example consider the recurrance:
>  : T(n) = T (n-1) + 1 where T(0) = 3
>      : T(1) = T(0) + 1, T(0) = 3, T(1) = T(0) + 1 = 3 + 1 = 4
> 
>      : T(2) = T(1) + 1, T(1) + 1 = 4 + 1 = 5 
> 
>      : T(3) = T(2) + 1, T(2) = 5, T(3) = 6
> 
>      Solution ⟶ T(n) = n + 3 ⇒ T(n)=Θ(n)

# Why integer arguments are not important

```c++
T(n) = 
        1,             n=1
        T(⌈ n × ½ ⌉),   n>1
```
`Let us try to solve it first for n=2ᵏ (in this case T always get integer arguments.)`

```
Claim is: T(n) = logn+1

T(n) = 
        logn+1  , n = 1
        logn+1  , n > 1

T(n) =            n = 1
        log1+1  , n = 1
        logn+1  , n > 1

T(n) =            log1 = 0
        log1+1  , n = 1
        logn+1  , n > 1

T(n) =            0 + 1 = 1
        1       , n = 1
        logn+1  , n > 1

.
.
.

```

> When n is not an power of 2?
>
> * lgn ≤ ⌈lgn⌉ 
> * 2ˡᴼᵍⁿ ≤ 2⌈ˡᵍⁿ⌉
> * n ≤ 2⌈ˡᵍⁿ⌉
> * T(n)≤T(2⌈ˡᵍⁿ⌉)
>   * lg2⌈ˡᵍⁿ⌉ + 1
>   * T(n) = ⌈lgn⌉ + 1
>   * COMPLETE HERE

# Why we can assume constant time on small inputs
> When functions are polynomially bounded, the initial condition (their result in smaller values) do not make a difference for the solution in asymptotic notations.
> : T(n) = T(n-1) + 1
> 
> T(0) = 3
> T(1) = T(0) + 1 = 3 + 1 = 4
> 
> T(2) = T(1) + 1 = 4 + 1 = 5
> 
> &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; .
> 
> &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; .
> 
> &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; .
>
> T(n) = n + 5
> 
> T(n) = Θ(n)
>
# Does matter when exponentially bounded!!!
> The initial conditions can make a differance, when the function is not polynomially bounded.
>
> Say we have T(n) = T(n/2)²
>
> : if T(1) = 2, T(n) = Θ(2ⁿ)
> : if T(1) = 3, T(n) = Θ(3ⁿ)
---

# Solving Recurrances
## Method 1: The Substitution Solution
> It has two step approach.
> 1. Guess the solution
> 2. Verify the solution
>
> Second step requires to perform induction method.
> 
> ### Example
>   Say we have T(n) = 4T(n/2) + n
>   
> Step 1
> : Guess and claim that T(n) = O(n³)
> 
> Step 2
> : Use the induction method to verify the guess.
>
>
> : * T(n) ≤ 2n³
> 
> : * T(n) ≤ 2n³
> 
> : * T(n) ≤ 7n³+2n²
>
> Try to prove a simple form, start with
>
> : * T(n) ≤ cn³
> 
> > Induction proof itself has two steps:
> > > 1. Induction Base:
> > > T(1) ?≤ c1³ ?≤ c, 
> > >   picked 1 as n₀.  We can always pick c big enough to satisfy this. T(n) = Ο(n³)
> > > 
> > > 2. Inductive Step: ∀ k<n, T(k) ≤ ck³
> > > 
> > >   
> > >       show: T(n) ≤ cn³


IF A BOUND IS BOTH UPPER AND LOWER BOUND IT IS A TIGHT BOUND 
>
> It is a powerful method for showing upper and lower bounds. (O and Θ)
---















<style>
    #important {
        color: red; 
    } 
    #note {
        color: #A5906D;
    }
</style>
---