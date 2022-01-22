#ifndef SORTS_QUICKSORT_HPP
#define SORTS_QUICKSORT_HPP

#include <vector>
#include <functional>
#include <random>
#include <algorithm>

#include "directionUtility.hpp"
#include "selectionSort.hpp"

enum PivotType {
  RIGHTMOST,
  RANDOM,
  RANDOM_MEDIAN
};

template <typename T>
void quickSort(std::vector<T> &collection, Direction direction, PivotType pivotType, long long start, long long finish)
{
  if (finish <= start) {
    return;
  }

  std::function<bool(T, T)> compare;
  switch (direction) {
    case ASCENDING:
      compare = isLess<T>;
      break;
    case DESCENDING:
      compare = isMore<T>;
      break;
  }

  std::size_t pivot;
  std::random_device rd;
  std::mt19937 mt(rd());
  switch (pivotType) {
    case RIGHTMOST:
      pivot = finish;
      break;
    case RANDOM:
      pivot = (mt() % (finish - start) + 1) + start;
      break;
    case RANDOM_MEDIAN:
      std::vector<uint32_t> rands;
      for (int i = 0; i < 2; ++i) {
        rands.push_back((mt() % (finish - start) + 1) + start);
      }
      selectionSort(rands, Direction::ASCENDING);
      pivot = rands[1];
  }
  std::swap(collection[finish], collection[pivot]);

  std::size_t u = start; //Begin of Unsorted part
  std::size_t q = start; //Begin of more-elements part
  for (std::size_t i = start; i <= finish; ++i) {
    if (i == finish) {
      std::swap(collection[i], collection[q]);
      break;
    }
    if (compare(collection[finish], collection[u])) {
      u++;
    } else {
      std::swap(collection[q], collection[i]);
      q++;
      u++;
    }
  }

  quickSort(collection, direction, pivotType, start, q - 1);
  quickSort(collection, direction, pivotType, q + 1, finish);
}

#endif //SORTS_QUICKSORT_HPP
