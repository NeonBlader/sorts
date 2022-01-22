# Sorting algorithms
This repository contains the following sorting algorithms:

* Heap sort
* Counting sort
* Insertion sort with binary search
* Selection sort
* Merge sort

**It is worth paying attention to the following points:**

* To use Heap sort, Insertion sort, Selection sort and Merge sort for some type in both directions, this type must have correct implementation of operator <

* Counting sort only supports non-negative integers

* When using merge sort, "start" is the index of the element from which the sorting subsequence begins, "finish" is the index of the element that ends the sorting subsequence (In both cases, inclusive)

To select the sort direction, you must pass the corresponding Direction::ASCENDING or Direction::DESCENDING argument as a function parameter
