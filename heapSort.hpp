#ifndef SORTS_HEAPSORT_HPP
#define SORTS_HEAPSORT_HPP

#include <cctype>
#include <vector>
#include <string>
#include <algorithm>

#include "directionUtility.hpp"

template<class T>
void heapify(std::vector<T> &collection, std::size_t i, std::size_t heapifyingPartEnd, std::function<bool(T,T)> compare)
{
  std::size_t max = i;
  std::size_t left = 2 * i + 1;
  std::size_t right = 2 * i + 2;

  if ((left < heapifyingPartEnd) && (compare(collection[left], collection[max]))) {
    max = left;
  }
  if ((right < heapifyingPartEnd) && (compare(collection[right], collection[max]))) {
    max = right;
  }
  if (max != i) {
    std::swap(collection[i], collection[max]);
    heapify(collection, max, heapifyingPartEnd, compare);
  }
}

template<class T>
void heapSort(std::vector<T> &collection, Direction direction)
{
  std::function<bool(T,T)> compare;
  switch (direction) {
    case ASCENDING:
      compare = isMore<T>;
      break;
    case DESCENDING:
      compare = isLess<T>;
  }
  for (int i = collection.size() / 2 - 1; i >= 0; i--) {
    heapify(collection, i, collection.size(), compare);
  }
  for (int i = collection.size() - 1; i >= 0; i--)
  {
    std::swap(collection[0], collection[i]);
    heapify(collection, 0, i, compare);
  }
}

#endif //SORTS_HEAPSORT_HPP
