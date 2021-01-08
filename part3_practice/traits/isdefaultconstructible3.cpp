#include <type_traits>

template <typename ...> using VoidT = void;

template <typename, typename = VoidT<>>
struct IsDefaultConstructibleT : std::false_type {};

template <typename T>
struct IsDefaultConstructibleT<T, VoidT<decltype(T())>> : std::true_type {};

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

