#include <cassert>
#include <iostream>
#include "accum5.hpp"

template <typename T>
struct MyAccumulationTraits;

template <>
struct MyAccumulationTraits<float> {
  using AccT = float;
  static constexpr AccT zero = 0.0f;
};

int main() {
  float num[] = { 1, 2, 3, 4, 5 };
  std::cout << "The average value of the integer values is "
            << accum<float, MyAccumulationTraits<float>>(num, num + 5) / 5
            << '\n';

  char name[] = "templates";
  int length = sizeof(name) - 1;

  int average = accum(name, name + length) / length;
  assert('a' <= average && average <= 'z');
  std::cout << "The (actual) average value of the characters in \""
            << name << "\" is " << average << '\n';
}

