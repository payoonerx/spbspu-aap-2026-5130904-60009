#include <cstddef>
#include <cstring>
#include <iostream>
#include <new>

namespace aristov
{
  char * replaceSym(char * dest, const char * src, char from, char to)
  {
    size_t i = 0;
    for (; src[i] != '\0'; ++i) {
      dest[i] = (src[i] == from) ? to : src[i];
    }
    dest[i] = '\0';
    return dest;
  }

  char * uniTwo(char * dest, const char * first, const char * second)
  {
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    while (first[i] != '\0' && second[j] != '\0') {
      dest[k++] = first[i++];
      dest[k++] = second[j++];
    }
    while (first[i] != '\0') {
      dest[k++] = first[i++];
    }
    while (second[j] != '\0') {
      dest[k++] = second[j++];
    }
    dest[k] = '\0';
    return dest;
  }

  char * readLine(std::istream & in)
  {
    size_t capacity = 16;
    size_t size = 0;
    char * buf = new (std::nothrow) char[capacity];
    if (!buf) {
      return nullptr;
    }
    char c = '\0';
    while (in.get(c) && c != '\n') {
      if (size + 1 >= capacity) {
        const size_t new_capacity = capacity * 2;
        char * const bigger = new (std::nothrow) char[new_capacity];
        if (!bigger) {
          delete[] buf;
          return nullptr;
        }
        std::memcpy(bigger, buf, size);
        delete[] buf;
        buf = bigger;
        capacity = new_capacity;
      }
      buf[size++] = c;
    }
    buf[size] = '\0';
    return buf;
  }
}

int main()
{
  const char * const second_literal = "def_";
  const char from = 'c';
  const char to = 'b';

  char * const input = aristov::readLine(std::cin);
  if (!input) {
    std::cerr << "Error: not enough memory\n";
    return 1;
  }

  const size_t len1 = std::strlen(input);
  if (len1 == 0 && std::cin.fail()) {
    std::cerr << "Error: empty input\n";
    delete[] input;
    return 1;
  }
  const size_t len2 = std::strlen(second_literal);

  char * const result10 = new (std::nothrow) char[len1 + 1];
  char * const result12 = new (std::nothrow) char[len1 + len2 + 1];
  if (!result10 || !result12) {
    std::cerr << "Error: not enough memory\n";
    delete[] input;
    delete[] result10;
    delete[] result12;
    return 1;
  }

  std::cout << aristov::replaceSym(result10, input, from, to) << "\n";
  std::cout << aristov::uniTwo(result12, input, second_literal) << "\n";

  delete[] input;
  delete[] result10;
  delete[] result12;
  return 0;
}
