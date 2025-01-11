#pragma once
#include <iostream>
#include <map>

class BitcoinExchange {
private:
  std::map<std::string, float> _db;

public:
  BitcoinExchange();
  virtual ~BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);

  void loadDatabase(const std::string &filename);
  void processInput(const std::string &inputFile);
  bool isValidDate(const std::string &date) const;
  bool isPositiveAmount(float amount) const;
  bool isNotToMuchAmount(float amount) const;
  bool isPositivePrice(float price) const;
  void printResult(const std::string &date, float amount, float value) const;
  void printError(const std::string &message) const;
  bool isNumeric(const std::string &str);
};