#include "RPN.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: ./RPN <expression>" << std::endl;
    return 1;
  }

  try {
    RPN rpn;
    float result = rpn.evaluate(argv[1]);
    std::cout << "Result: " << result << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
