/**
 * @file selection_problem.cpp
 * @author Egemen Kilic (egemenkilic@sabanciuniv.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-27
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 * 
 * ! Selection Problem
 * * - Finding the kᵗʰ largest (or smallest) element.
 * * - We saw algorithms using a heap, best was Ο(N×logk)
 * *  
 * ! Quick Select
 * * - Given set S and k:
 * *    → If |S| = 1, then k = 1, return the element in S.
 * *    → If |S| ≠ 1, then:
 * *        → Pick a pivot element v.
 * *        → Apply Partition Algorithm S - {v}, just like QuickSort. 
 * *        → If k ≤ |S₁|, then the kᵗʰ smallest element is in S₁. Return quickSelect(S₁, k) .
 * *        → If k = |S₁| + 1, then return v as the answer. It means kₜₕ smallest element is not in S₁.
 * *        → If k ≥ |S₁| + 1, then return quickSelect(S₂, k - |S₁| - 1).
 * * - QuickSelect makes one recursive call, QuickSort makes two recursive calls.
 * *    → Worst case time is: Ο(N²).
 * *    → Average case time is: Ο(N).
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