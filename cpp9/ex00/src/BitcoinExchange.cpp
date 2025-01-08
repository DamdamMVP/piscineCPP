#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange() { loadDatabase("data.csv"); }

BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	this->_db = other._db;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other){
	if(this != &other){
		this->_db = other._db;
	}
	return *this;
}

void BitcoinExchange::loadDatabase(const std::string &filename) {
  std::ifstream file(filename);
  std::string line;

  if (!file.is_open()) {
    printError("Error: could not open file.");
    return;
  }

  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string date;
    float price;

    if (std::getline(ss, date, ',') && ss >> price) {
      _db[date] = price;
    }
  }
  file.close();
}
