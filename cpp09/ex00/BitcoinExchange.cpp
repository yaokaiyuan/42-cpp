#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cctype>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : _rates(other._rates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _rates = other._rates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& dbFile) {
    loadDatabase(dbFile);
}

void BitcoinExchange::loadDatabase(const std::string& dbFile) {
    std::ifstream file(dbFile.c_str());
    if (!file) {
        throw std::runtime_error("Error: could not open database file.");
    }
    std::string line;
    // Skip header of database file
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, rateStr;
        if (!std::getline(iss, date, ',')) continue;
        if (!std::getline(iss, rateStr)) continue;
        // Trim whitespace
        date.erase(date.find_last_not_of(" \t") + 1);
        date.erase(0, date.find_first_not_of(" \t"));
        rateStr.erase(rateStr.find_last_not_of(" \t") + 1);
        rateStr.erase(0, rateStr.find_first_not_of(" \t"));
        std::istringstream rateStream(rateStr);
        double rate;
        rateStream >> rate;
        if (rateStream.fail()) continue;
        _rates[date] = rate;
    }
}

double BitcoinExchange::getRateForDate(const std::string& date) const {
    std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);
    if (it != _rates.end() && it->first == date) {
        return it->second;
    }
    if (it == _rates.begin()) {
        throw std::runtime_error("Error: no rate available for this date or before.");
    }
    --it; // Move to the previous date
    return it->second;
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.size(); ++i) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(date[i])) return false;
    }
    int year, month, day;
    std::istringstream(date.substr(0, 4)) >> year;
    std::istringstream(date.substr(5, 2)) >> month;
    std::istringstream(date.substr(8, 2)) >> day;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    static const int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month == 2) {
        bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > 28 + leap) return false;
    } else {
        if (day > daysInMonth[month - 1]) return false;
    }
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, double& value) {
    std::istringstream iss(valueStr);
    iss >> value;
    if (!iss || !iss.eof()) return false;
    if (value < 0) return false;
    if (value > 1000) return false;
    return true;
}
