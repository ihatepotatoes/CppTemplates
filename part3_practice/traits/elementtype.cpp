#include <iostream>
#include <list>
#include <typeinfo>
#include <vector>
#include "elementtype.hpp"

template <typename T>
void printElementType(T const& c) {
  std::cout << "Container of "
            << typeid(typename ElementT<T>::Type).name()
            << " elements.\n";
}

int main() {
  std::vector<bool> s;
  printElementType(s);
  int arr[42];
  printElementType(arr);
}

