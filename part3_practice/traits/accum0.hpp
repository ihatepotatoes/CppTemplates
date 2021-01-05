#pragma once

#include <iterator>

template <typename Iter>
auto accum(Iter start, Iter end) {
  using VT = typename std::iterator_traits<Iter>::value_type;

  VT total{}; // assume this actually create a zero value
  while (start != end) {
    total += *start;
    ++start;
  }
  return total;
}

