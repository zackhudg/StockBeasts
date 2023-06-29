#ifndef STOCKAPI_H
#define STOCKAPI_H

#include <string>
#include <vector>
#include <unordered_set>

struct StockData {
    std::string ticker;
    float price;
    int volume;
    // Add any additional stock data fields as needed
};

class StockAPI {
public:
    StockAPI(const std::string& apiKey);

    bool fetchStockData(const std::unordered_set<std::string>& tickers, std::vector<StockData>& stockData);

private:
    std::string apiKey_;
};

#endif  // STOCKAPI_H
