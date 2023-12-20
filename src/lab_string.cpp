#include "lab_string.hpp"

#include <cstring>
#include <memory>
#include <chrono>

#include <ostream>

namespace stdlike {

void String::Construct(const char* ptr) {
  size_t size = strlen(ptr);
  data_ = new char[size+1];
  data_[size] = '\0';
  std::memcpy(data_, ptr, size);
}

String::String() : data_(nullptr) {}

String::String(size_t size) {
  data_ = new char[size+1];
  memset(data_, 1, sizeof(char) * size);
  data_[size] = '\0';
}

String::String(const char* ptr) {
  Construct(ptr);
}

String::String(const String& other) {
  Construct(other.data_);
}

String& String::operator=(const char* ptr) {
  if(Size() == strlen(ptr)) {
    std::memcpy(data_, ptr, Size());
  } else {
    delete[] data_;
    Construct(ptr);
  }
  return *this;
}

String& String::operator=(const String& other) {
  return (*this = other.data_);
}

String::String(String&& other) {
  data_ = other.data_;
  other.data_ = nullptr;
}

String& String::operator=(String&& other) {
  delete[] data_;
  data_ = other.data_;
  other.data_ = nullptr;
  return *this;
}

size_t String::Size() const {
  if(!data_) return 0;
  return strlen(data_);
}

const char* String::Data() const {
  return data_;
}

const char& String::operator[](size_t index) const {
  return data_[index];
}
char& String::operator[](size_t index) {
  return data_[index];
}

String::~String() {
  delete[] data_;
}

std::ostream& operator<<(std::ostream& stream, const String& str) {
  const char* c_str = str.Data();
  stream << c_str;
  return stream;
}

String GenerateRandom(size_t size) {
  String str(size);
  for(size_t i = 0; i < size; ++i) {
    str[i] = std::rand() % 26 + 97;
  }
  return str;
}

bool operator<(const String& a, const String& b) {
  size_t min_len = std::min(a.Size(), b.Size());
  for(size_t i = 0; i < min_len; ++i) {
    if(a[i] == b[i]) continue;
    else if(a[i] < b[i]) return true;
    else return false;
  }
  return a.Size() < b.Size();
}

bool operator>(const String& a, const String& b) {
  return b < a;
}

bool operator==(const String& a, const String& b) {
  if(a.Size() != b.Size()) return false;
  for(size_t i = 0; i < a.Size(); ++i) {
    if(a[i] != b[i]) return false;
  }
  return true;
}

bool operator!=(const String& a, const String& b) {
  return !(a == b);
}

#ifdef __GNUC__
String::iterator String::Begin() {
  return iterator(data_);
}

String::iterator String::End() {
  return iterator(data_ + Size());
}

String::const_iterator String::Begin() const {
  return const_iterator(data_);
}

String::const_iterator String::End() const {
  return const_iterator(data_ + Size());
}
#endif

}