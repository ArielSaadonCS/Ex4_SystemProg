
This project implements a generic container class (`MyContainer`) that supports multiple iterator types. The container can hold any comparable type and provides six different iteration orders.

Files:

* `MyContainer.hpp`: The main file containing the template class and all implementations of the container and its iterators.
* `Main.cpp`: A sample run demonstrating the project’s functionality.
* `Test.cpp`: A comprehensive test file checking the project’s methods, using `doctest.h`.

Classes:

* `MyContainer<T>`: A generic container class supporting dynamic add/remove operations.
* `AscendingOrderIterator`: Iterates over elements in ascending order.
* `DescendingOrderIterator`: Iterates over elements in descending order.
* `SideCrossOrderIterator`: Alternates between the smallest and largest remaining elements.
* `ReverseOrderIterator`: Iterates in reverse insertion order.
* `OrderIterator`: Iterates in the original insertion order.
* `MiddleOutOrderIterator`: Starts from the middle element and alternates left/right.

Container operations:

* `add()`: Adds an element to the container.
* `remove()`: Removes all occurrences of an element (throws an exception if not found).
* `size()`: Returns the number of elements.
* `operator<<`: Output operator for printing.

Each iterator type provides:

* `begin()` and `end()` methods.
* `operator*()` for accessing the value.
* `operator++()` for advancing.
* `operator==()` and `operator!=()` for comparison.

Commands:

* Compile and run example program:
  make Main

* Compile and run tests:
  make test

* Check for memory leaks:
  make valgrind

* Clean build files:
  make clean
