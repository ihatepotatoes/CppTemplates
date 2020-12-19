#include <iostream>

class C {
public:
  C() { std::cout << "default ctor\n"; }
  // C(C const&) = delete; // It won't compile.
  C(C const volatile&) = delete;
  template <typename T>
  C(T const&) { std::cout << "tmpl copy ctor\n"; }
};

int main() {
  C x;
  C y{ x };
  C z{ 42 };
}
