#include <iostream>

template <auto Value>
struct just_wrapper {
  decltype(Value) value = Value;
};

int main() {
  just_wrapper<42> iw;
  std::cout << iw.value << std::endl;
  just_wrapper<true> dw;
  std::cout << dw.value << std::endl;
}
