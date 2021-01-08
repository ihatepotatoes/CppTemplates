#include <utility>

template <typename F, typename... Args,
          typename = decltype(std::declval<F>()(std::declval<Args&&>()...))>
std::true_type isValidImpl(void *);

template <typename F, typename... Args>
std::false_type isValidImpl(...);

inline constexpr auto isValid = [](auto f) {
  return [](auto&&... args) {
    return decltype(isValidImpl<decltype(f),
                                decltype(args)&&...
                               >(nullptr)){};
  };
};

template <typename T>
struct TypeT {
  using Type = T;
};

template <typename T>
constexpr auto type = TypeT<T>{};

template <typename T>
T valueT(TypeT<T>);

