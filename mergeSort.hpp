#ifndef SORTS_MERGESORT_HPP
#define SORTS_MERGESORT_HPP

#include <vector>
#include <functional>
#include <cstddef>
#include <iterator>

#include "directionUtility.hpp"

template <typename T>
void mergeSort(std::vector<T> &collection, Direction direction, std::size_t start, std::size_t finish)
{
  std::function<bool(T, T)> compare;
  switch (direction) {
    case ASCENDING:
      compare = isLess<T>;
      break;
    case DESCENDING:
      compare = isMore<T>;
      break;
  }

  if (start >= finish) {
    return;
  }

  std::size_t middle = (start + finish) / 2;
  mergeSort(collection, direction, start, middle);
  mergeSort(collection, direction, middle + 1, finish);

  std::vector<T> left(collection.begin() + start, std::next(collection.begin() + middle));
  std::vector<T> right(collection.begin() + middle + 1, std::next(collection.begin() + finish));

  for (std::size_t i = start; (!left.empty()) || (!right.empty()); ++i) {
    if (left.empty()) {
      collection[i] = right[0];
      right.erase(right.begin());
    } else if (right.empty()) {
      collection[i] = left[0];
      left.erase(left.begin());
    } else if (compare(left[0], right[0])) {
      collection[i] = left[0];
      left.erase(left.begin());
    } else {
      collection[i] = right[0];
      right.erase(right.begin());
    }
  }
}

#endif //SORTS_MERGESORT_HPP
