# C++ Header-only Templated Implementation of Circular List

No `new` or `delete`. Using Smart Pointers.

your type needs to have `operator==`.

Usage:

```cpp
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
```

Results:

```
List elements:
24
32
30
Is list empty? No
Size of list: 3
Is 70 in the list? No
Is 24 in the list? Yes
List elements:
24
30
60
30
Next item is in index: 1 and its value: 30
Next item is in index: 2 and its value: 60
Next item is in index: 3 and its value: 30
Next item is in index: 0 and its value: 24
Next item is in index: 1 and its value: 30
Next item is in index: 2 and its value: 60
Next item is in index: 3 and its value: 30
Next item is in index: 0 and its value: 24
Next item is in index: 1 and its value: 30
Next item is in index: 2 and its value: 60
Next item is in index: 3 and its value: 30
Next item is in index: 0 and its value: 24
Next item is in index: 1 and its value: 30
Next item is in index: 2 and its value: 60
Next item is in index: 3 and its value: 30
Clearing the list
Size of the list: 0
```
