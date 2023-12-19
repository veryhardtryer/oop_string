#pragma once 

#include <cstddef>
#include <ostream>

#ifdef __GNUC__
#include <array_iterator.hpp>
#endif

namespace stdlike {

class String {
 public:
  String();
  explicit String(size_t size);
  String(const char* ptr);
  
  String(const String& other);
  String& operator=(const String& other);
  String& operator=(const char* other);

  String(String&& other);
  String& operator=(String&& other);

  size_t Size() const;
  const char* Data() const;

  const char& operator[](size_t index) const;
  char& operator[](size_t index);

  friend std::ios& operator<<(std::ios& stream, const String& str);

  ~String();

  #ifdef __GNUC__
  using iterator = ArrayIterator<char>;
  using const_iterator = ArrayIterator<const char>;

  iterator Begin();
  iterator End();
  const_iterator Begin() const;
  const_iterator End() const;

  iterator begin() { return Begin(); }
  iterator end() { return End(); }
  const_iterator begin() const { return Begin(); }
  const_iterator end() const { return End(); }
  #endif

 private:
  
  void Construct(const char* ptr);

 private:
  char* data_;
};

String GenerateRandom(size_t size);

bool operator<(const String& a, const String& b);
bool operator>(const String& a, const String& b);
bool operator==(const String& a, const String& b);
bool operator!=(const String& a, const String& b);

}