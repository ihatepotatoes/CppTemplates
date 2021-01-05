#include <iostream>
#include <typeindex>

template <typename T>
struct A {
  A(const T&) {}
  using type = T;
};

// The deduction guide itself.
// Looks like it helps to deduce template class argument
// basing on constructors argument(s?).
A(const char[7]) -> A<const char *>;
// This mechanism called CTAD (Class Template Argument Deduction).

int main() {
  A a(5);
  std::cout << typeid(typename decltype(a)::type).name() << std::endl;

  A b(5.0);
  std::cout << typeid(typename decltype(b)::type).name() << std::endl;

  A c("string");
  std::cout << typeid(typename decltype(c)::type).name() << std::endl;
}
