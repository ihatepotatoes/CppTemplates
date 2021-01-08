#include <iostream>
#include <type_traits>

template <typename T>
struct IsDefaultConstructibleHelper {
private:
  template <typename U, typename = decltype(U())>
  static std::true_type test(void*);

  template <typename>
  static std::false_type test(...);
public:
  using Type = decltype(test<T>(nullptr));
};

template <typename T>
struct IsDefaultConstructibleT : IsDefaultConstructibleHelper<T>::Type {};

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

