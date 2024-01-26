---
Date: Monday 03-27-2023 | 11:26:25
Updated at: Monday 03-27-2023 | 18:56:07
Author: Egemen Kılıç
---

# Question 1
## (a) [5 points] What is the form of the input array that triggers the worst case of the insertion sort?
> Worst case for insertion sort occurs when the input array is in reverse sorted order. It's the case when each element is greater than all of the elements that come before it. 
## (b) [5 points] What is the complenity of this worst–case behavior in Θ notation?
> $$\small \text{The complexity is Θ(n²).}$$
> $$\small \text{For n elements we are making n × (n-1) × 1/2 comparisons and swaps.}$$
> > The formula comes from the following logic.
> > : ⟶ We have n elements and before inserting a new element, we need to make sure that n-1ᵗʰ element is greater than all the previous elements, so we need to compare the current element with n-1 elements. 
> $$\normalsize \text {Therefore the comlexity is Θ(n²).}$$
## (c) [10 points] Explain how this particular form of the array results in this complexity.
> The algorithm must shift all the elements into their correct index, hence causing a shift opearation on all elements. Algorithm needs to select the n-1ᵗʰ element and compare it with the previous elements (n≥2) until the array is in sorted order.
> 
> [5,4,3,2,1] to [1,2,3,4,5] as an example.
> : ⟶ 5 4 3 2 1
> : ⟶ 4 5 3 2 1  (Take 4, compare it with 5. 1 comparison & 1 swap)
> : ⟶ 3 4 5 2 1  (Take 3, compare it with 5 and 4. 2 comparison & 2 swap)
> : ⟶ 2 3 4 5 1  (Take 2, compare it with 5, 4, and 3. 3 comparison & 3 swap)
> : ⟶ 1 2 3 4 5  ( Take 1, compare it with 5, 4, 3, and 2. 4 comparison & 4 swap)
>
> ⟹ The array is of n elements, and we have a total of `1+2+3+4 comparsions` and  `1+2+3+4 swaps`. Resulting in `10 comparisons and 10 swaps`. Which could be found with:  
> $$n * (n-1), \small \text {Not dividing it by 2 because we need the total number of operations.}$$  
> $$\small \text{For n = 10, we have 5 x 4 = 20 operations.}$$

# Question 2
## (a) [5 points] What is the form of the input array that triggers the best case of the insertion sort?
> The best case for insertion sort occurs when the input array is already sorted or nearly sorted in ascending order. Opposite from the worst case, here every element is sorted so we don't need to make any swapping or comparison operations until we hit the value to be sorted.
## (b) [5 points] What is the complexity of this best–case behavior in Θ notation?
> Since the input array is sorted or nearly sorted, we only need to make n-1 comparisons and 1 swap operation to put the value at the correct index. So n-1 comparisons and 1 swap opeartion will result in n operations, which means that the best-case behaviour has the time complexity of Θ(n). 
## (c) [10 points] Explain how this particular form of the array results in this complexity.
> For an already sorted array, we don't need to make any comparisons or swap operations. For a nearly sorted array like [1, 2, 4, 3, 5], we only need to make n-1 comparisons and 1 swap opearation. Therefore the complexity is Θ(n) time. It means that the number of comparison and swap operations grow linearly with the size of the input array.
# Question 3 [50pts] Suppose that you're trying to prove (5n+4)² = Ο(n²) by using the formal definition of Ο-*notation*, where *n*≥0. In order to show that (5n+4)² = Ο(n²) by using the formal definition of Ο-*notation*, we need to pick constants *c* and *n₀* such that for any  n≥n₀ we have (5n+4)² ≤ cn².
## (a) [25 points] If you use n₀ = 2, what is the smallest c value that makes the proof go through?
> From the definition given in the question, we need n≥0 and n₀≥n such that for n≥n₀, (5n+4)² ≤ cn². We need to use n₀=2, so n≥2. 
> * If we plug in n=2 for(5n+4)², weg et (10+4)² = 196.
> * The definition says that 196 ≤ c(2)², so 196 ≤ 4c, where we find 49 ≤ c. So the smallest value that satisfies for c when n₀=2 is 49.
## (b) [25 points] If you use c = 36, what is the smallest n0 value that makes the proof go through?
> Again from the definition, for n≥0 and n₀≥n such that for n≥n₀, (5n+4)² ≤ cn². 
> * We have c=36, which results in 25n² + 40n + 16 ≤ 36n². 
> * The equation turns into 0 ≤ 11n² - 40n - 16.
> * If we write the equation in form (11n+4)(n-4), we get:
>   * 11n² - 44n + 4n - 16 = 11n² - 40n - 16.
> * Roots of this equation are 
> $$ n-4=0, n₁=4 \hspace{.5cm} \small \text{ and} \hspace{.5cm}  11n=-4, n₂=-4/11$$
> We have the condition of n≥0, so n≠-4/11, n₀=n₁=4. 
> So the smallest value for n₀ that makes the proof go through when c=36 is 4.

# Question 4 [10 points] Rank the following functions in descending order with respect to their growth rates.
$$ 2^{2^{n}} > n! > n\cdot2^{n}\ > \log_{2}\left(n\right)!\ > \log_{2}\left(n!\right) > \log_{2}^{2}n\ \small\text{ For n≥1}$$ 