# Sorting algorithms
This repository contains the following sorting algorithms:

* Heap sort
* Counting sort
* Insertion sort with binary search

**It is worth paying attention to the following points:**

* To use Heap sort and Insertion sort for some type, this type must have appropraite operators:

| Algorithm      | Ascending  | Descending |
|----------------|------------|------------|
| Heap sort      | operator > | operator < |
| Insertion sort | operator < | operator > |

* Counting sort only supports non-negative integers

To select the sort direction, you must pass the corresponding Direction::ASCENDING or Direction::DESCENDING argument as a function parameter
