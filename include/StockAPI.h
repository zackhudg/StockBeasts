#ifndef STOCKAPI_H
#define STOCKAPI_H

#include <string>
#include <vector>

struct StockData {
    std::string ticker;
    float price;
    int volume;
    // Add any additional stock data fields as needed
};

class StockAPI {
public:
    StockAPI(const std::string& apiKey);

    bool fetchStockData(std::unordered_map<std::string, StockData>& stockData);

private:
    std::string apiKey_;
};

#endif  // STOCKAPI_H
