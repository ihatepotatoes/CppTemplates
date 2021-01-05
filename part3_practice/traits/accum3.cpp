#include <cassert>
#include <iostream>
#include "accum3.hpp"

int main() {
  int num[] = { 1, 2, 3, 4, 5 };
  std::cout << "The average value of the integer values is "
            << accum(num, num + 5) / 5 << '\n';

  char name[] = "templates";
  int length = sizeof(name) - 1;

  int average = accum(name, name + length) / length;
  assert('a' <= average && average <= 'z');
  std::cout << "The (actual) average value of the characters in \""
            << name << "\" is " << average << '\n';
}

