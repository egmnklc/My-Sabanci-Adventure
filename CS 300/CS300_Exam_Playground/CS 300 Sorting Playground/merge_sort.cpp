/**
 * @file merge_sort.cpp
 * @author Egemen Kilic (egemenkilic@sabanciuniv.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-26
 * 
 * @copyright Copyright (c) 2022
 * *
 * *
 * *
 * ! Merge Sort
 * * Uses Divide and Conquer Algorithm
 * * low (l) → lowest value index
 * * high (h)→ highest value index
 * * 
 * * if ( l < h )
 * *    mid = (l+h)/2 
 * *    mergesort (l, mid)
 * *    mergesort (mid+1, high)
 * *    merge(l, mid, h)
 * * 1  2  3  4  5  6 7 8 9 ⇒ Indexes
 * * 9  3  7  5  6  4  8  2 ⇒ Array to be merge sorted
 * * |        |           |
 * * l       mid          h
 * *
 * * - Time complexity for merge sort: Ο(NlogN)
 * *
 * * - 
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