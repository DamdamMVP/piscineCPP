#include "ScalarConverter.hpp"
#include <cmath>
#include <limits>
#include <sstream>

const char *ScalarConverter::ErrorDoubleConvert::what() const throw() {
  return "Can't convert ";
}

double stringToDouble(const std::string &str) {
  std::istringstream iss(str);
  double value;
  iss >> value;
  if (iss.fail() || !iss.eof()) {
    throw ScalarConverter::ErrorDoubleConvert();
  }
  return value;
}

bool isSpecialDemand(const std::string &str) {
  if (str == "nan" || str == "+inf" || str == "-inf" || str == "nanf" ||
      str == "+inff" || str == "-inff" || str == "inff" || str == "inf") {
    return true;
  }
  return false;
}

void ScalarConverter::convert(const std::string &s) {
  char charValue;
  int intValue;
  float floatValue;
  double doubleValue;

  try {
    if (isSpecialDemand(s)) {
      std::cout << "char: impossible" << std::endl;
      std::cout << "int: impossible" << std::endl;
      if (s == "+inff") {
        std::cout << "float : +inff" << std::endl;
        std::cout << "double : +inf" << std::endl;
      } else if (s == "-inff") {
        std::cout << "float : -inff" << std::endl;
        std::cout << "double : -inf" << std::endl;
      } else if (s == "nanf") {
        std::cout << "float : nanf" << std::endl;
        std::cout << "double : nan" << std::endl;
      } else if (s == "inff") {
        std::cout << "float : inff" << std::endl;
        std::cout << "double : inf" << std::endl;
      } else {
        std::cout << "float : " << s << "f" << std::endl;
        std::cout << "double : " << s << std::endl;
      }
	  return ;
    }
    doubleValue = stringToDouble(s);
    intValue = static_cast<int>(doubleValue);
    floatValue = static_cast<float>(doubleValue);
    charValue = static_cast<char>(intValue);

    if (std::isprint(charValue))
      std::cout << "char: '" << charValue << "'" << std::endl;
    else
      std::cout << "char: Non displayable" << std::endl;

    std::cout << "int: " << intValue << std::endl;

    if (floatValue == intValue)
      std::cout << "float: " << floatValue << ".0f" << std::endl;
    else
      std::cout << "float: " << floatValue << "f" << std::endl;

    if (doubleValue == intValue)
      std::cout << "double: " << doubleValue << ".0" << std::endl;
    else
      std::cout << "double: " << doubleValue << std::endl;

  } catch (const std::exception &e) {
    std::cerr << e.what() << "'" << s << "'" << std::endl;
  }
}