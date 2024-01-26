//* ⨍ : intbar
//* 𝚯 : mbfTheta
//! Brute-Force Algorithms
//! Groups will be selecting a problem from a pool of questions
//*
//! Instance of a problem: Consists of all the inputs that satisfy the constarints that are imposed by the problem definition.
//! Correct algorithm: An algorithm is correct if for every instance the problem,
//*     it halts(terminates, stopping at the right time) and produces the correct answer.
//*     Otherwise is an incorrect algorithm. There are occasions where we use incorrect algorithms.
//*
// ! Incorrect algorithms may be faster than the correct algorithm, but it does not provide always the true answer.
//*
//! Insertion Sort: Inserting a number into an already sorted array. Precondition is a sorted array.
//* How can we use this idea to sort an unsorted sequence?
//*     Suppose we have: [3, 1, 7, 2]
//*     -> [3]
//*     -> [1, 3]
//*     -> [1, 2, 3]
//*     -> [1, 2, 3, 7]
//* ⟶ Lmao this is hows
//*
//* Insertion-Sort(A)
//* {
//*     for (j=2; j<=n; j+=1)
//*     {
//*         num = A[j];
//*         i = j-1;
//*         // Find the correct place for num
//*         while (i > 0 and A[i] > num) //→ Searches for the correct place to insert the next element
//*         {
//*             A[i+1] = A[i];i-=1;
//*         }
//*         A[i+1] = num;
//*     }
//*   }
//*
//! Loop Invariants: Widely used method to show the correctness of iterative algorithms.
//!     Method is preformed in 3 steps, and related to the mathematical induction proofs.
//!
//! A loop invariant is a boolean statement (true or false) that is correct for all the iterations of the loop.
//!     Should state true for all iterations, thorught the iterations of main loop, of an algorithms. 
//*     The 3 steps of loop invariant method
//*     1. Initialization
//*         → Show that the loop invariant holds before the first iteration of the loop, similar to the induction base in inductive proofs.
//*     2. Maintenance 
//*         → If the loop invariant is correct after n iterations, it will be also correct after n iterations. 
//*         Show that if the loop invariant holds be/fore an interation of the loop, 
//*         then it also holds at thte end of the iteration (and hence at the beginning of the next iteration) of the loop.
//*             2. adimdan once dogru calistiysa ikinci adimdan sonra da dogru calisacak diyoruz. 
//*             Invariant diyoruz cunku dogruluk degeri algoritmanin calisma seklinden bagimsiz, yani dogruysa calisacak, algoritma soyleyse degil.
//*         Similar to the induction step
//*     3. Termination
//*         → When the loop terminates, the invariant gives a useful property that helps to show that the algorithm is correct.
//*         
//! A loop invariant for Insertion Sort
//*     Insertion-Sort(A)
//*     {
//*         for (j=2; j<=n; j+=1)
//*         {
//*             num = A[j];
//*             i = j-1;
//*             // Find the correct place for num
//*             while (i > 0 and A[i] > num) //→ Searches for the correct place to insert the next element
//*             {
//*                 A[i+1] = A[i];i-=1;
//*             }
//*             A[i+1] = num;
//*         }
//*     }
//*     Step 3
//*         - When algoritm terminates, it means j > n. Since we increment j by 1 in each iteration, we know that j = n + 1.
//*         - The loop invariant for j = n + 1 states that:
//*             - A[1...]
//* 
//*  Burda step 1 2 3 varmis sanirim kacirdim burayi
//*
//* Is Insertion sort the solution for the sorting problem?
//*     - Insetion sort is only a solution for the sorting problem.
//*  .....
//*
//* What do we mean by a "better algorithm"?
//*     - An algorithm is better if it uses less resources than other algorithms. 
//*         → Time, Space, Money, Area, Bandwith, Energy, etc...
//*     - Using less resources depends on
//*         → The number of input elements
//*         → The characteristics of the input
//*         → The resource we are interested in.
//*     So using the best algorithm known does not solve the issue!
//*     - Definition of best will change.
//*
//*     Selecting the BEST algorithm:
//*         → Selecting the best algorithm requires to have multiple algorithms for the solution for a problem. 
//*         →  The resource which our selection will be made should be known
//!         →  We MUST analyze the avaliable algoruthms to understand how much of the type of resources we are ineterested these algorithms use 
//*         →  We must have a specific model of implementation for the analysis. 
//*             We will mainly use RAM model, where the algorithms are implemented as single thread computer programs.
//*      
//* Analysis of Insertion Sort
//*     → Time taken by insertion sort depends on:
//*     - The number of elements to be sorted, 100 vs 1000 elements.
//*     → The nature of the input
//*     - Almost sorted, reverse sorted, etc...
//*     → In general, the time taken by an algoruthm grows with the size of the input.
//*     → Therefore we describe the running time of an algorithm !!!!!!!!!!!!!!!!!!!!!!!!
//*
//* Definition of the input size
//*     → It depends on the problem and sometimes on the algorithm. 
//*     → For sorting problem, it is natural to pick the # of elements as the size of the input.
//*     → However, for some sorting algorithms, range of numbers to be sorted may be used as the size of the input, because the behaviour of the algorithm depends on such a factor.
//* 
//* Definition of running time
//*     → 
//*
//*
//*
//*
//*
//*
//*
//* ................................................
//*
//* 
//* 
//* 
//* Which running time should we use?
//*     ⟶  Worst case running time is used because:  
//*         → It gives an upper bound, can't go worse.
//*     ⟶ Murphy's law, the worst case happens
//*     ⟶ Average case is usually the same as the worst case.
//* 
//* Asymptotic Analyis
//*     ⟶ Suppose we have two algorithms say A₁ and A₂ 
//*     ⟶ Let the running times:
//*         → T₁(n) = 2n³ and T₂(n) = 50n² 
//*     ⟶ A₁ will need 2 * (10⁵)³ instructions, 10⁹ instrictions/sec = 2 × 10⁶ million seconds
//* 
//*     ⟶ Look at the growth of T(n) as n ⟶ ∞     
//*     ⟶ ...............
//* 
//* Algorithm Design Techniques
//* ⟶ There are some general methodoligies/techniques can be used to classify algorithms.
//* 
//* Divide and Conquer'da kaldik.
//* 