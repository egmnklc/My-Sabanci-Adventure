/**
 * @file sorting_12.cpp
 * @author Egemen Kilic (egemenkilic@sabanciuniv.com)
 * @brief
 * @version 0.1
 * @date 2022-12-26
 *
 * @copyright Copyright (c) 2022
 * *
 * *
 * revemptyset ⦰
 * bigcap ⋂
 * bigcup ⋃
 * rightwavearrow ↝
 * upTheta Θ
 * upOmicron Ο
 * strns ⏤
 * lceil  ⌈
 * rceil  ⌉
 * lfloor ⌊
 * rfloor ⌋
 *
 * ! Sorting
 * * - Internal Sorting
 * *    - All data to be sorted fits in the main memory.
 * * - External Sorting
 * *    - Sorting that cannot be completed in main memory, extrenal memory such as disks are needed.
 * * Focus is internal sorting.
 * * - Any general purpose sorting algorithm requires Ω(NlogN) comparisons.
 * * - There are several simple algorithms that sort in O(N²) time (Insertion Sort).
 * * - Shell Sort runs in Ο(N²) time, and is efficient in practice.
 * * - There are Ο(NlogN) sorting algorithms.
 * *
 * * ⇒ Best sorting algorithm is Quick Sort, average time of Ο(NlogN), worst case of Ο(N²).
 * *
 * *
 * *
 * ! Insertion Sort (Inserting into an already sorted ↝ Descending order)
 * * - Insertion sort consists of N-1 passes.
 * *    - Interchanges are always between adjacent elements.
 * *    - For pass p = 1 to N - 1:
 * *        - Relies on the fact that elements 0 through p-1 are already in sorted order.
 * *        - ENSURES that elements 0 through p are sorted in order.
 * * - In pass p, we move the element in position p left until it finds correct place among p+1 elements.
 * *
 * * ⏤ Example
 * *    - 34  8  64  51  32  21 ⇒ Initial State
 * *    - 8  34  64  51  32  21 ⇒ After pass 1, 8 moved 1 position.
 * *    - 8  34  64  51  32  21 ⇒ After pass 2, 64 moved 0 position.
 * *    - 8  34  51  64  32  21 ⇒ After pass 3, 51 moved 1 position.
 * *    - 8  32  34  51  64  21 ⇒ After pass 4, 32 moved 3 position.
 * *    - 8  21  32  34  51  64 ⇒ After pass 6, 21 moved 4 positions.
 * *    - And we are done, total number of inversions: 1+0+1+3+4=9.
 * *        - They are: (34,8), (34,32), (34,21) (64,51), (64,32), (64,21), (51,32), (51,21), (32,21)
 * ! Insertion Sort Code Example (Total Comparisons → Θ(N²) )
 * !      template <class Comparable>
 * !      void insertionSort (vector <Comparable> & a)
 * !      {
 * !      	int j
 * !                     // loop over the passes
 * !      	for (int p = 1;  p < a.size(); p++)
 * !      	{
 * !      		Comparable tmp = a[p];
 * !                                  // loop over the elements
 * !      		for (j = p; j > 0 &&  tmp < a[j – 1]; j ––)
 * !      			a[j] = a[j –1];
 * !      		a[j] = tmp;
 * !      	}
 * !      }
 * * Analysis: If the input is already sorted, insertion sort is very fast.
 * *
 * ! Lower Bound
 * * - We can provide a lower bound for simple sorting algorithms that operate by interchanging
 * *   adjacent elements.
 * *   - Inversion Example: (i,j) ⇒ i > j, but indexOf(i) < indexOf(j).
 * *    **Number of inversions = number of positions moved, why?
 * *      - Each adjacent swap fixes one inversion and a sorted array has no inversions.
 * *
 * * - Since there are Ο(N) passes, total work or insertion sort is Ο(N+I),
 * *   where I is the initial initial number of inversions.
 * * - Number of inversions: Ο(N)
 * * - Insertion sort takes Ο(N) time.
 * *
 * *
 * *
 * *
 * ! Shell Sort
 * * - One of the first algorithms that breaks the quadratic time barrier.
 * * - Works by comparing distant elements.
 * *    - The distance between comparisons decreases as the algorithm continues.
 * *    - Shellsort is also referred to as diminishing increment sort.
 * *
 * * - Shellsort uses a sequence of increments h₁, h₂ , h₃, ...,  hₜ .
 * *    - Any increment sequence will do as long as h₁ = 1.
 * * - After a phase using some increment hₖ, for every i, we have a[i] < a[i+hₖ]
 * *    (where a[i+hₖ] exists) all elements spaced hₖ apart are hₖ-sorted.
 * ? Note: An important property of Shellsort is that an hₖ-sorted sequence that is
 * ?       then hₖ₋₁ sorted remains hₖ sorted.
 * *
 * * - A popular but poor choice for increments:
 * *    -  hₜ = ⌊ N / 2 ⌋ ∧ hₖ = ⌊ hₖ₊₁ / 2 ⌋, these are called Shell's increments
 * *    -  Mesela h₁=8 ise h₂=4, h₃=2, h₄=1. hₜ = 1 olunca da duruyoruz. 
 * ! Shell sort degistirdigi elemanin yerini dogrulamak icin mevcut hₖ degerini geriye giderek de 
 * !    kontrol ediyor. Bir kere calismiyor yani, dogru yere gelene kadar devam ediyor.
 * *
 * * Analysis: Worst-case running time using Shell's Increment: θ(N²)
 * * - Lower-bound ⇒ Ω(N²)
 * * - Upper-bound ⇒ Ο(N²)
 * *
 * ? Note: The problem with Shell's increment is that pairs of increments are not relatively prime.
 * ? so smaller increments have little effect.
 * *
 * *
 * *
 * * Hibbard's Increments: 1, 3, 7, ..., 2ᵏ-1.
 * * - Consecutive increments have no comment factors (arka arkaya olan sayilar aralarinda asallar.)
 * * - Worst case is Ω (N^(3/2))    
 * *
 * *
 * *
 * *
 * *
 * *
 * *
 * *
 * *
 * *
 * *
 */