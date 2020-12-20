#include <iostream>
#include <vector>

template <typename T, unsigned N>
void printLen(T(&)[N]) {
  std::cout << "Number of elements in a raw array: " << N << '\n';
}

template <typename T,
          typename = decltype( (void)(T{}.size()), typename T::size_type{} )>
void printLen(T const& t) {
  std::cout << "Number of elements for a type having size_type: "
            << t.size() << '\n';
}

void printLen(...) {
  std::cout << "Fallback for all other types\n";
}

int main() {
  int a[10];
  printLen(a);
  printLen("tmp");

  std::vector<int> v;
  printLen(v);

  int *p;
  printLen(p);

  std::allocator<int> x;
  printLen(x);
}
