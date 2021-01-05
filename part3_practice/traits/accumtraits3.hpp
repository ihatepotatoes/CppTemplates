template <typename T>
struct AccumulationTraits;

template <>
struct AccumulationTraits<char> {
  using AccT = int;
  static constexpr AccT zero = 0;
};

template <>
struct AccumulationTraits<short> {
  using AccT = int;
  static constexpr AccT zero = 0;
};

template <>
struct AccumulationTraits<int> {
  using AccT = long;
  static constexpr AccT zero = 0l;
};

template <>
struct AccumulationTraits<unsigned int> {
  using AccT = unsigned long;
  static constexpr AccT zero = 0ul;
};

template <>
struct AccumulationTraits<float> {
  using AccT = double;
  static constexpr AccT zero = 0.0f;
};

