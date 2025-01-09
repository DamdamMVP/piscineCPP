#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
  if (ac == 2) {
    BitcoinExchange btc;
    btc.processInput(av[1]);
  } else {
    std::cerr << "Error: ./btc <filename>" << std::endl;
  }
  return 0;
}