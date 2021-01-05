#pragma once

#include "accumtraits3.hpp"

template <typename T, typename AT = AccumulationTraits<T>>
auto accum(T const* begin, T const* end) {
  typename AT::AccT total = AT::zero;
  while (begin != end) {
    total += *begin;
    ++begin;
  }
  return total;
}

