#ifndef SORTS_INSERTIONSORTWITHBINARYSEARCH_HPP
#define SORTS_INSERTIONSORTWITHBINARYSEARCH_HPP

#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <functional>

#include "directionUtility.hpp"

template <class T>
void insertionSortWithBinarySearch(std::vector<T> &collection, Direction direction)
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
  for (std::size_t i = 1; i < collection.size(); ++i) {
    if (!(compare(collection[i], collection[i - 1]))) {
      continue;
    }
    T current  = collection[i];
    std::size_t high = i - 1;
    std::size_t low = 0;
    while (low < high) {
      std::size_t middle = low + (high - low) / 2;
      if (compare(current, collection[middle])) {
        high = middle;
      } else {
        low = middle + 1;
      }
    }
    for (int j = i; j != low ; --j) {
      collection[j] = collection[j - 1];
    }
    collection[low] = current;
  }
}

#endif //SORTS_INSERTIONSORTWITHBINARYSEARCH_HPP
