#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const std::string& dbFile);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    double getRateForDate(const std::string& date) const;
    static bool isValidDate(const std::string& date);
    static bool isValidValue(const std::string& valueStr, double& value);

private:
    void loadDatabase(const std::string& dbFile);
    std::map<std::string, double> _rates;
};

#endif
