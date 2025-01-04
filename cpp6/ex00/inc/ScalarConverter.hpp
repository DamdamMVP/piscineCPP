#pragma once
#include <iostream>

class ScalarConverter {
private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &other);
  ScalarConverter &operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
  };
  ~ScalarConverter(){};

public:
  class ErrorDoubleConvert : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  static void convert(const std::string &s);
};