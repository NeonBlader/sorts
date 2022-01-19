#include "directionUtility.hpp"

#include <stdexcept>

Direction convertDirection(const std::string &direction)
{
  if (direction == "ascending") {
    return ASCENDING;
  }
  if (direction == "descending") {
    return DESCENDING;
  }
  throw std::invalid_argument("Invalid Direction");
}
