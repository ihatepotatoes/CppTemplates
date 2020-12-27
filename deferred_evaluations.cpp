#include <string>

template <typename T>
class Cont {
  T* elems;
public:
  template <typename D = T>
  std::conditional_t<std::is_move_constructible_v<D>,
                     D&&,
		     D&>
  foo();
};

struct Node {
  std::string value;
  Cont<Node> next;
};
