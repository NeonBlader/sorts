# Sorting algorithms
This repository contains the following sorting algorithms:

* Heap sort
* Counting sort
* Insertion sort with binary search
* Selection sort
* Merge sort
* Quick sort

**It is worth paying attention to the following points:**

* To use Heap sort, Insertion sort, Selection sort, Merge sort and Quick sort for some type in both directions, this type must have correct implementation of operator <

* Counting sort only supports non-negative integers

* When using merge sort, "start" is the index of the element from which the sorting subsequence begins, "finish" is the index of the element that ends the sorting subsequence (In both cases, inclusive)

To select the sort direction, you must pass the corresponding Direction::ASCENDING or Direction::DESCENDING argument as a function parameter

To select a pivot type in Quicksort, pass as a function parameter:

* PivotType::RIGHTMOST - if want pivot always to be rightmost element
* PivotType::RANDOM - if want pivot to be random element
* PivotType::RANDOM_MEDIAN - if want pivot to be median of 3 random elements
