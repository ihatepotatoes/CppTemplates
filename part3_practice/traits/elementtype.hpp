#pragma once

#include <list>
#include <vector>

template <typename C>
struct ElementT {
  using Type = typename C::value_type;
};

template <typename T, std::size_t N>
struct ElementT<T[N]> {
  using Type = T;
};

template <typename T, std::size_t N>
struct ElementT<T(&)[N]> {
  using Type = T;
};

template <typename T>
struct ElementT<T[]> {
  using Type = T;
};

template <typename T>
struct ElementT<T(&)[]> {
  using Type = T;
};

template <typename T>
struct ElementT<T*> {
  using Type = T;
};

