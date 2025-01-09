#pragma once

#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

class RPN {
private:
  RPN(const RPN &other);
  RPN &operator=(const RPN &other);
  bool isOperator(const std::string &token) const;
  float applyOperator(const std::string &op, float a, float b) const;
  bool isNumber(const std::string &token) const;

public:
  RPN();
  ~RPN();
  float evaluate(const std::string &expression);
};