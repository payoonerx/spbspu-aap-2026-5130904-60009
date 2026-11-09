#include <cstddef>
#include <iostream>

namespace aristov {

int run() {
  using namespace std;

  const size_t INITIAL_CAPACITY = 16;
  const size_t GROWTH_FACTOR = 2;

  long long *data = nullptr;
  size_t size = 0;
  size_t capacity = 0;
  long long num = 0;
  bool zero_seen = false;

  while (cin >> num) {
    if (num == 0) {
      zero_seen = true;
      break;
    }

    if (size == capacity) {
      const size_t new_capacity =
          capacity == 0 ? INITIAL_CAPACITY : capacity * GROWTH_FACTOR;

      long long *const new_data = new long long[new_capacity];

      for (size_t i = 0; i < size; ++i) {
        new_data[i] = data[i];
      }

      delete[] data;
      data = new_data;
      capacity = new_capacity;
    }

    data[size++] = num;
  }

  if (!zero_seen) {
    delete[] data;
    cerr << "Invalid input\n";
    return 1;
  }

  if (size == 0) {
    delete[] data;
    cerr << "Sequence is too short\n";
    return 2;
  }

  size_t grt_lss = 0;

  for (size_t i = 1; i + 1 < size; ++i) {
    if (data[i] < data[i - 1] && data[i] > data[i + 1]) {
      ++grt_lss;
    }
  }

  long long max_val = data[0];
  size_t max_pos = 0;

  for (size_t i = 1; i < size; ++i) {
    if (data[i] > max_val) {
      max_val = data[i];
      max_pos = i;
    }
  }

  const size_t aft_max = size - max_pos - 1;

  cout << grt_lss << '\n';
  cout << aft_max << '\n';

  delete[] data;

  return 0;
}

} // namespace aristov

int main() { return aristov::run(); }
