#pragma once

#include "accumtraits3.hpp"

template <typename T>
auto accum(T const* begin, T const* end) {
  // return type is traits of the element type
  using AccT = typename AccumulationTraits<T>::AccT;

  AccT total = AccumulationTraits<T>::zero; // init total by trait value
  while (begin != end) {
    total += *begin;
    ++begin;
  }
  return total;
}

