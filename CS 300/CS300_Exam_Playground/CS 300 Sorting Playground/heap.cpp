/**
 * @file heap.cpp
 * @author Egemen Kilic (egemenkilic@sabanciuniv.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-26
 * 
 * @copyright Copyright (c) 2022
 * 
 * ! Heap 
 * * Insert Operation
 * ? Note: From the max heap whenever you delete, you get the largest element form the heap.
 * * - While inserting, insert the element at the out of memory index location ((Length of array + 1) ᵗʰ index).
 * * - After that, move the leaf from the position where it should be by performing switching operations. 
 * * - Heap Insertion takes Ο(logN) time.
 * * - For N elements, Heap Insertion Takes Ο(N×LogN) time.
 * * Deletion Operation
 * * - When you delete, the last element in the array becomes the root, after that you align the nodes accordingly.
 * * - Heap Deletion takes Ο(logN) time.
 * *
 * * Heap Sort Operation
 * * - When you delete form the heap and store the deleted elements in memory spaces outside of the heap, you achieve heap sort.
 * *
 * ? Note: Height of a complete binary tree: logN.
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