#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}

bool RPN::isOperator(const std::string &token) const {
  return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(const std::string &token) const {
  for (size_t i = 0; i < token.length(); i++) {
    if (!std::isdigit(token[i]) && token[i] != '.' &&
        (i != 0 || token[i] != '-')) {
      return false;
    }
  }
  return true;
}

float RPN::applyOperator(const std::string &op, float a, float b) const {
  if (op == "+")
    return a + b;
  if (op == "-")
    return a - b;
  if (op == "*")
    return a * b;
  if (op == "/") {
    if (b == 0)
      throw std::runtime_error("Error: division by zero");
    return a / b;
  }
  throw std::runtime_error("Error: invalid operator");
}

float RPN::evaluate(const std::string &expression) {
  std::stack<float> stack;
  std::stringstream ss(expression);
  std::string token;

  while (ss >> token) {
    if (isNumber(token)) {
      stack.push(std::stof(token));
    } else if (isOperator(token)) {
      if (stack.size() < 2) {
        throw std::runtime_error("Error: insufficient values in stack");
      }
      float b = stack.top();
      stack.pop();
      float a = stack.top();
      stack.pop();
      stack.push(applyOperator(token, a, b));
    } else {
      throw std::runtime_error("Error: invalid token in expression");
    }
  }

  if (stack.size() != 1) {
    throw std::runtime_error("Error: invalid expression");
  }

  return stack.top();
}
