#pragma once

template <typename T>
T accum(T const* begin, T const* end) {
  T total{}; // assume this actually creates a zero value
  while (begin != end) {
    total += *begin;
    ++begin;
  }
  return total;
}

