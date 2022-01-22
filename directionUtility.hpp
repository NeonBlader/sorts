#ifndef SORTS_DIRECTIONUTILITY_HPP
#define SORTS_DIRECTIONUTILITY_HPP

#include <string>

enum Direction {
  ASCENDING,
  DESCENDING
};

template<class T>
bool isLess(const T &left, const T &right)
{
  return left < right;
}

template <class T>
bool isMore(const T &left, const T &right)
{
  return right < left;
}

template <class T, class = typename std::enable_if<std::is_integral<T>::value>::type>
void incrementCounter(T &counter)
{
  counter++;
}

template <class T, class = typename std::enable_if<std::is_integral<T>::value>::type>
void decrementCounter(T &counter)
{
  counter--;
}

#endif //SORTS_DIRECTIONUTILITY_HPP
