#include <cstddef>
#include <iostream>

namespace aristov
{

int run()
{
  const std::size_t INITIAL_CAPACITY = 16;
  const std::size_t GROWTH_FACTOR = 2;

  long long *data = nullptr;
  std::size_t size = 0;
  std::size_t capacity = 0;
  long long value = 0;

  while (std::cin >> value)
  {
    if (value == 0)
    {
      break;
    }

    if (size == capacity)
    {
      const std::size_t new_capacity =
          capacity == 0 ? INITIAL_CAPACITY : capacity * GROWTH_FACTOR;

      long long *new_data = new long long[new_capacity];

      for (std::size_t i = 0; i < size; ++i)
      {
        new_data[i] = data[i];
      }

      delete[] data;
      data = new_data;
      capacity = new_capacity;
    }

    data[size] = value;
    ++size;
  }

  if (size == 0)
  {
    delete[] data;
    std::cout << "0\n0\n";
    return 0;
  }

  std::size_t grt_lss = 0;

  for (std::size_t i = 1; i + 1 < size; ++i)
  {
    if (data[i] < data[i - 1] && data[i] > data[i + 1])
    {
      ++grt_lss;
    }
  }

  long long max_value = data[0];
  std::size_t max_position = 0;

  for (std::size_t i = 1; i < size; ++i)
  {
    if (data[i] > max_value)
    {
      max_value = data[i];
      max_position = i;
    }
  }

  const std::size_t aft_max = size - max_position - 1;

  std::cout << grt_lss << '\n';
  std::cout << aft_max << '\n';

  delete[] data;
  return 0;
}

}

int main()
{
  return aristov::run();
}
