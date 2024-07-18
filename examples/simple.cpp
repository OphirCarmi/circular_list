#include <iostream>

#include "circular_list.h"

int main() {
  CircularList<int> list;

  // Inserting some items
  list.Insert(24);
  list.Insert(32);
  list.Insert(30);

  list.Print();

  std::cout << "Is list empty? " << (list.Empty() ? "Yes" : "No") << std::endl;
  std::cout << "Size of list: " << list.Size() << std::endl;
  std::cout << "Is 70 in the list? " << (list.Find(70) ? "Yes" : "No") << std::endl;
  std::cout << "Is 24 in the list? " << (list.Find(24) ? "Yes" : "No") << std::endl;

  // Removing existing item
  list.Remove(32);

  // Trying to remove non-existing item
  list.Remove(64);

  // Inserting some more items
  list.Insert(60);

  // Inserting duplicate values
  list.Insert(30);

  list.Print();

  // Next() will always show a value (if the list is not empty)
  for (int i = 0; i < 15; ++i) {
    int curr = -1;
    list.Next(&curr);
    int j = list.Index();
    std::cout << "Next item is in index: " << j << " and its value: " << curr << std::endl;
  }

  std::cout << "Clearing the list" << std::endl;
  list.Clear();
  std::cout << "Size of the list: " << list.Size() << std::endl;

  return 0;
}