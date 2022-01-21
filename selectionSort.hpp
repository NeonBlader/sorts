#ifndef SORTS_SELECTIONSORT_HPP
#define SORTS_SELECTIONSORT_HPP

#include <vector>
#include <functional>

#include "directionUtility.hpp"

template <typename T>
void selectionSort(std::vector<T> &collection, Direction direction)
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
  for (std::size_t i = 0; i < collection.size() - 1; ++i) {
    std::size_t localM = i;
    for (std::size_t j = i + 1; j < collection.size(); ++j) {
      if (compare(collection[j], collection[localM])) {
        localM = j;
      }
    }
    std::swap(collection[i], collection[localM]);
  }
}

#endif //SORTS_SELECTIONSORT_HPP
