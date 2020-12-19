#include <bitset>
#include <iostream>

template<std::size_t N>
void printBitset(std::bitset<N> const& bs) {
  // It won't compile without ".template "
  std::cout << bs.template to_string<char, std::char_traits<char>,
                            std::allocator<char>>()
            << std::endl;
}

int main() {
  std::size_t i = 42;
  std::bitset<sizeof(decltype(i))> bs(i);
  printBitset(bs);
}
