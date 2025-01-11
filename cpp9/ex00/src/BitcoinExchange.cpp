#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange() { loadDatabase("data.csv"); }
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
  this->_db = other._db;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other) {
    this->_db = other._db;
  }
  return *this;
}

void BitcoinExchange::loadDatabase(const std::string &filename) {
  std::ifstream file(filename.c_str());
  std::string line;

  if (!file.is_open()) {
    printError("Error: could not open file.");
    return;
  }

  std::getline(file, line);
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string date;
    float price;

    if (std::getline(ss, date, ',')) {
      ss >> price;

      if (!isValidDate(date)) {
        printError("Error 'data.csv': invalid date => " + date);
        continue;
      }

      if (!isPositivePrice(price)) {
        printError("Error 'data.csv': not a positive price.");
        continue;
      }
      _db[date] = price;
    } else {
      printError("Error 'data.csv': bad input format => " + line);
    }
  }
  file.close();
}

void BitcoinExchange::processInput(const std::string &inputFile) {
  std::ifstream file(inputFile.c_str());
  std::string line;

  if (!file.is_open()) {
    printError("Error: could not open input file.");
    return;
  }

  std::getline(file, line);
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string date;
    std::string amountStr;
    float amount;

    if (std::getline(ss, date, '|')) {
      std::getline(ss, amountStr);
      date.erase(date.find_last_not_of(" ") + 1);

      if (!isValidDate(date)) {
        printError("Error: invalid date => " + date);
        continue;
      }

      if (!isNumeric(amountStr)) {
        printError("Error: invalid amount format => " + amountStr);
        continue;
      }

      std::stringstream amountStream(amountStr);
      amountStream >> amount;

      if (!isPositiveAmount(amount)) {
        printError("Error: not a positive number.");
        continue;
      }

      if (!isNotToMuchAmount(amount)) {
        printError("Error: too large a number.");
        continue;
      }

      std::map<std::string, float>::const_iterator it = _db.lower_bound(date);

      if (it == _db.end() || it->first != date) {
        if (it != _db.begin()) {
          --it;
        } else {
          printError("Error: no data available for date => " + date);
          continue;
        }
      }

      float result = amount * it->second;
      printResult(date, amount, result);
    } else {
      printError("Error: bad input format => " + line);
    }
  }
  file.close();
}

bool BitcoinExchange::isValidDate(const std::string &date) const {
  if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
    return false;
  }

  int year = atoi(date.substr(0, 4).c_str());
  int month = atoi(date.substr(5, 2).c_str());
  int day = atoi(date.substr(8, 2).c_str());

  if (year < 1900 || month < 1 || month > 12 || day < 1 || day > 31) {
    return false;
  }

  if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
    return false;
  }

  if (month == 2) {
    bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    if (day > (isLeapYear ? 29 : 28)) {
      return false;
    }
  }

  return true;
}

bool BitcoinExchange::isPositiveAmount(float amount) const {
  return (amount >= 0.0f);
}

bool BitcoinExchange::isPositivePrice(float price) const {
  return (price >= 0.0f);
}

bool BitcoinExchange::isNotToMuchAmount(float amount) const {
  return (amount <= 1000.0f);
}

void BitcoinExchange::printResult(const std::string &date, float amount,
                                  float value) const {
  std::cout << date << " => " << amount << " = " << value << std::endl;
}

void BitcoinExchange::printError(const std::string &message) const {
  std::cerr << message << std::endl;
}

bool BitcoinExchange::isNumeric(const std::string &str) {
  size_t start = str.find_first_not_of(" ");
  size_t end = str.find_last_not_of(" ");
  if (start == std::string::npos) {
    return false;
  }

  std::string trimmed = str.substr(start, end - start + 1);

  bool hasDecimalPoint = false;

  for (size_t i = 0; i < trimmed.length(); ++i) {
    if (trimmed[i] == '.') {
      if (hasDecimalPoint || i == 0 || i == trimmed.length() - 1) {
        return false;
      }
      hasDecimalPoint = true;
    } else if (!std::isdigit(trimmed[i])) {
      return false;
    }
  }

  return true;
}
