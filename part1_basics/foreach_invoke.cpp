#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <utility>

template <typename Iter, typename Callable, typename... Args>
void foreach(Iter current, Iter end, Callable op, Args const&... args) {
  while (current != end) {
    std::invoke(op,
                args...,
		*current);
    ++current;
  }
}

void PrintHypotenuse(double a, double b) {
  std::cout << std::sqrt(a * a + b * b) << '\n';
}

class HypotenuseFinder {
  double a{ 0 };
public:
  HypotenuseFinder(double _a) : a{ _a } {}

  void FindAndPrint(double b) const {
    std::cout << std::sqrt(a * a + b * b) << '\n';
  }
};

int main() {
  double arr[] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6 };
  
  foreach(std::begin(arr), std::end(arr), &PrintHypotenuse, 2.0);
  
  foreach(std::begin(arr), std::end(arr), [] (double a, double b) {
    std::cout << std::sqrt(a * a + b * b) << '\n';
  }, 2.0);

  foreach(std::begin(arr), std::end(arr), &HypotenuseFinder::FindAndPrint,
          HypotenuseFinder{ 2.0 });
}
