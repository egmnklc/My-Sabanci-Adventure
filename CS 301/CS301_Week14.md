---
Date: Monday 06-05-2023 | 14:02:57
Updated at: Monday 06-05-2023 | 14:02:54
---

## Sorting Problem
> Θ(nlogn) lower bound is a comparison based sorting problem that is obtained by RAM. 
> : We can implement the sorting algorithms using hardware.

## Comparators
> Sorting networks are based on comparison networks, and comparison networks are based on comparators.
>
> **`Comparator is a function that gives max and min values of its input.`**
>
> **Recurrance formula for comparator based sorting is:** `C(n)=C(n-1)+n-1`

## Monotonic and Bitonic Sequences
> ![](2023-06-05-14-30-09.png)

## Bitonic 0-1 Sequences
> ![](2023-06-05-14-31-49.png)

## Half Cleaner (assuming n is even)
> A bitonic sorter is composed of several stages of each of which is called a half cleaner.

## Half Cleaner For 8 Inputs
> ![](2023-06-05-14-35-13.png)

## Bitonic Sorter
> We can design a sorting network or bitonic sequences using half cleaners recursively.

## Bitonic Sorter Example for 8 Inputs
> ![](2023-06-05-14-37-14.png)

## Sorter With 8 Inputs Using Merger Blocks
> ![](2023-06-05-14-38-33.png)

## Sorter With 8 Inputs Using Explicit Comparators
> ![](2023-06-05-14-40-33.png)