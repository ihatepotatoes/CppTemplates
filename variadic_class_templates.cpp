#include <array>
#include <iostream>
#include <string>
#include <tuple>

template <typename T>
class AddSpace {
  const T& ref;
public:
  AddSpace(const T& r) : ref(r) {}
  friend std::ostream& operator<<(std::ostream& os, const AddSpace<T>& s) {
    return os << s.ref << ' ';
  }
};

template <typename... Args>
void print(Args&& ... args) {
  (std::cout << ...  << AddSpace(args)) << '\n';
}

template <std::size_t...>
struct Indices {};

template <typename T, std::size_t... Idx>
void printByIdx(T&& t, Indices<Idx...>) {
  print(std::get<Idx>(t)...);
}

int main() {
  std::array<std::string, 5> arr{ "Hello", "my", "new", "!", "World" };
  printByIdx(arr, Indices<0, 4, 3>());

  auto t = std::make_tuple(12, "monkeys", 2.0);
  printByIdx(t, Indices<0, 1, 2>());
}
