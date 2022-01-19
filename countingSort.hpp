#ifndef SORTS_COUNTINGSORT_HPP
#define SORTS_COUNTINGSORT_HPP

#include <vector>
#include <string>
#include <cctype>
#include <functional>
#include <stdexcept>

#include "directionUtility.hpp"

template<class T, class = typename std::enable_if<std::is_integral<T>::value>::type>
void countingSort(std::vector<T> &collection, T min, T max, Direction direction)
{
  if (min < 0) {
    throw std::invalid_argument("Minimum element can't be negative for counting sort");
  }
  std::function<void(std::size_t&)> changeCounter;
  switch (direction) {
    case ASCENDING:
      changeCounter = incrementCounter<std::size_t>;
      break;
    case DESCENDING:
      changeCounter = decrementCounter<std::size_t>;
      break;
  }
  std::vector<T> temp(max - min + 1, 0);
  for (const std::size_t &i : collection) {
    temp[i - min]++;
  }
  std::size_t startPos = 0;
  for (std::size_t i = ((direction == ASCENDING) ? 0 : temp.size() - 1); (i < temp.size() && (i >= 0)); changeCounter(i)) {
    for (int j = 0; j < temp[i]; ++j) {
      collection[startPos] = i + min;
      startPos++;
    }
  }
}

#endif //SORTS_COUNTINGSORT_HPP
