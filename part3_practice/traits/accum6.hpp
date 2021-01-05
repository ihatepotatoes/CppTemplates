#pragma once

#include "accumtraits3.hpp"
#include "sumpolicy1.hpp"

template <typename T,
          typename Policy = SumPolicy,
          typename Traits = AccumulationTraits<T>>
auto accum(T const* begin, T const* end) {
  using AccT = typename Traits::AccT;
  AccT total = Traits::zero;
  while (begin != end) {
    Policy::accumulate(total, *begin);
    ++begin;
  }
  return total;
}

