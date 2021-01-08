#include <iostream>
#include <type_traits>

template <typename T>
struct IsDefaultConstructibleT {
private:
  template <typename U, typename = decltype(U())>
  static char test(void*);

  template <typename>
  static long test(...);
public:
  static constexpr bool value =
    std::is_same_v<decltype(test<T>(nullptr)), char>;
};

template <typename T>
static constexpr bool IsDefaultConstructible =
  IsDefaultConstructibleT<T>::value; 

struct S {
  S() = delete;
};

int main() {
  static_assert(IsDefaultConstructible<int>);
  static_assert(!IsDefaultConstructible<S>);
}

