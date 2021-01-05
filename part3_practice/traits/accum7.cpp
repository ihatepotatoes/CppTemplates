#include <cassert>
#include <iostream>
#include "accum7.hpp"

template <typename T1, typename T2>
class MultPolicy {
public:
  static void accumulate(T1& total, T2 const& value) {
    total *= value;
  }
};

int main() {
  int num[] = { 1, 2, 3, 4, 5 };
  std::cout << "The product of the integer values is "
            << accum<int, MultPolicy>(num, num + 5)
            << '\n';

  char name[] = "templates";
  int length = sizeof(name) - 1;

  int average = accum(name, name + length) / length;
  assert('a' <= average && average <= 'z');
  std::cout << "The (actual) average value of the characters in \""
            << name << "\" is " << average << '\n';
}

