#pragma once

#include "accumtraits2.hpp"

template <typename T>
auto accum(T const* begin, T const* end) {
  // return type is traits of the element type
  using AccT = typename AccumulationTraits<T>::AccT;

  AccT total{}; // assume this actually creates a zero value
  while (begin != end) {
    total += *begin;
    ++begin;
  }
  return total;
}

