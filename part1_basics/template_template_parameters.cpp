#include <algorithm>
#include <iostream>
#include <iterator>
#include <deque>
#include <vector>

template <typename Elem, typename Cont>
struct A {
  using Elems = Cont;
  Elems elems;

  void Print() {
    std::copy(elems.cbegin(), elems.cend(),
              std::ostream_iterator<Elem>{ std::cout, ", " });
    std::cout << '\n';
  }
};

// C++11
// template <typename Elem, template <typename ...> class Cont>
// C++17
template <typename Elem, template <typename> class Cont>
struct B : A<Elem, Cont<Elem>> {};

// C++11
// template <typename Elem, template <typename ...> class Cont>
// C++17
template <typename Elem, template <typename> class Cont>
Cont<Elem> C() {
  return {};
}

// C++11
// template <typename Elem, template <typename ...> class Cont>
// C++17
template <typename Elem, template <typename> class Cont>
using D = Cont<Elem>;

int main() {

  A<int, std::vector<int>> a;
  // A<int, std::vector> a; // It won't compile.
  a.elems.push_back(41);
  a.Print();

  B<int, std::vector> b;
  b.elems.push_back(42);
  b.Print();

  auto c = C<int, std::vector>();
  c.push_back(43);
  std::cout << c[0] << std::endl;

  D<int, std::vector> d({ 44 });
  std::cout << d[0] << std::endl;
}
