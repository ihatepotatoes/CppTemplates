#include <iostream>
#include <string>
#include <type_traits>
#include <utility>

// C++17
template <typename T>
using EnableIfString = std::enable_if_t<
                         std::is_convertible_v<T, std::string>>;

// C++20
template <typename T>
concept ConvertibleToString = std::is_convertible_v<T, std::string>;

class Person
{
  std::string name;

public:
  // generic constructor for passed initial name:
  // C++17
  // template <typename STR, typename = EnableIfString<STR>>
  // C++20
  // template <typename STR>
  // requires std::is_convertible_v<STR, std::string>
  // C++20, another one option
  template <ConvertibleToString STR>
  explicit Person(STR && n) : name(n) {
    std::cout << "TMPL-CONSTR for ’" << name << "’\n";
  }

  // copy and move constructor:
  Person (Person const& p) : name(p.name) {
    std::cout << "COPY-CONSTR Person ’" << name << "’\n";
  }

  Person (Person&& p) : name(std::move(p.name)) {
    std::cout << "MOVE-CONSTR Person ’" << name << "’\n";
  }
};

int main()
{
  std::string s = "sname";
  Person p1(s); // init with string object => calls copying string-CONSTR
  Person p2("tmp"); // init with string literal => calls moving string-CONSTR
  Person p3(p1); // copy Person => calls COPY-CONSTR
  Person p4(std::move(p1)); // move Person => calls MOVE-CONST
}

