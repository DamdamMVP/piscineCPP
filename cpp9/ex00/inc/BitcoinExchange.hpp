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
  float calculateValue(const std::string &date, float amount) const;
  bool isValidDate(const std::string &date) const;
  bool isValidAmount(float amount) const;
  void printResult(const std::string &date, float amount, float value) const;
  void printError(const std::string &message) const;
};