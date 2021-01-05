#include <cassert>
#include <iostream>
#include "accum1.hpp"

int main() {
  int num[] = { 1, 2, 3, 4, 5 };
  std::cout << "The average value of the integer values is "
            << accum(num, num + 5) / 5 << '\n';

  char name[] = "templates";
  int length = sizeof(name) - 1;

  auto average = accum(name, name + length) / length;
  assert(average < 'a');
  std::cout << "The overflown (!) average value of the characters in \""
            << name << "\" is " << average << '\n';
}

