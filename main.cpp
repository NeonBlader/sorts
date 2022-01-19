#include <iostream>
#include <cmath>
#include <ctime>

#include "insertionSortWithBinarySearch.hpp"
#include "countingSort.hpp"
#include "heapSort.hpp"
#include "timer.cpp"

void averageTimeTest()
{
  srand(time(0));
  for (int i = 10; i <= 100000; i *= 10) {
    std::vector<int> collection;
    for (int j = 0; j < i; j++) {
      collection.push_back(rand());
    }
    Timer timer;
    insertionSortWithBinarySearch(collection, Direction::ASCENDING);
    std::cout << "Insertion sort with " << i << " elements: " << timer.elapsed() << '\n';
    collection.clear();
    for (int j = 0; j < i; j++) {
      collection.push_back(rand() % 1000);
    }
    timer.reset();
    countingSort(collection, 0, 1000, Direction::ASCENDING);
    std::cout << "Counting sort with " << i << " elements: " << timer.elapsed() << '\n';
    collection.clear();
    for (int j = 0; j < i; j++) {
      collection.push_back(rand());
    }
    timer.reset();
    heapSort(collection, Direction::ASCENDING);
    std::cout << "Heap sort with " << i << " elements: " << timer.elapsed() << "\n \n";
  }
}

void bestTimeTest()
{
  std::vector<int> collection;
  for (int i = 0; i <= 100000; ++i) {
    collection.push_back(i);
  }
  Timer timer;
  insertionSortWithBinarySearch(collection, Direction::ASCENDING);
  std::cout << "Insertion sort with 10000 elements " << timer.elapsed() << '\n';
  countingSort(collection, 0, 1000000, Direction::ASCENDING);
  timer.reset();
  std::cout << "Counting sort with 10000 elements " << timer.elapsed() << '\n';
  timer.reset();
  heapSort(collection, Direction::ASCENDING);
  std::cout << "Heap sort with 10000 elements " << timer.elapsed() << "\n \n";
}

void worstTimeTest()
{
  std::vector<int> collection;
  for (int i = 0; i < 100000; ++i) {
    collection.insert(collection.begin(), i);
  }
  Timer timer;
  insertionSortWithBinarySearch(collection, Direction::ASCENDING);
  std::cout << "Insertion sort with 10000 elements " << timer.elapsed() << '\n';
  countingSort(collection, 0, 100000, Direction::ASCENDING);
  timer.reset();
  std::cout << "Counting sort with 10000 elements " << timer.elapsed() << '\n';
  timer.reset();
  heapSort(collection, Direction::ASCENDING);
  std::cout << "Heap sort with 10000 elements " << timer.elapsed() << "\n \n";
}

int main()
{
  std::cout << "Best time cases:\n";
  bestTimeTest();
  std::cout << "\n \nAverage time cases:\n";
  averageTimeTest();
  std::cout << "\n  \nWorst time cases:\n";
  worstTimeTest();
  return 0;
}