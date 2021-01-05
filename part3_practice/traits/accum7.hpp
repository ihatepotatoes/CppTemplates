#pragma once

#include "accumtraits3.hpp"
#include "sumpolicy2.hpp"

template <typename T,
          template <typename, typename> class Policy = SumPolicy,
          typename Traits = AccumulationTraits<T>>
auto accum(T const* begin, T const* end) {
  using AccT = typename Traits::AccT;
  AccT total = Traits::zero;
  while (begin != end) {
    Policy<AccT, T>::accumulate(total, *begin);
    ++begin;
  }
  return total;
}

