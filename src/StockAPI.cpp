#define NOMINMAX
#include <algorithm>
#include "StockAPI.h"
#include <iostream>
#include <string>
#include <curl/curl.h>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

// Callback function for curl to write received data
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* buffer) {
    size_t totalSize = size * nmemb;
    buffer->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

StockAPI::StockAPI(const std::string& apiKey) : apiKey(apiKey) {
    // Initialize any necessary variables or configurations
    curl_global_init(CURL_GLOBAL_ALL);
}

bool StockAPI::initStockMap(std::unordered_map<std::string, StockData>& stockData, int numRandomStocks) {
    std::string symbolUrl = "https://finnhub.io/api/v1/stock/symbol?exchange=US&token=" + apiKey;

    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to initialize CURL." << std::endl;
        return false;
    }

    std::string response;
    curl_easy_setopt(curl, CURLOPT_URL, symbolUrl.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    if (res != CURLE_OK) {
        std::cerr << "Failed to fetch stock symbols: " << curl_easy_strerror(res) << std::endl;
        return false;
    }

    json jsonData = json::parse(response);
    std::vector<std::string> symbols;

    // Extract stock symbols from the API response
    for (const auto& entry : jsonData) {
        if (entry["type"] == "Common Stock") {
            symbols.push_back(entry["symbol"]);
        }
    }

    // Select random stock symbols
    srand(static_cast<unsigned int>(time(NULL))); // Seed the random number generator
    std::random_shuffle(symbols.begin(), symbols.end());
    int numSelectedStocks = std::min(numRandomStocks, static_cast<int>(symbols.size()));

    // Fetch stock data for selected stock symbols and populate the stock map
    for (int i = 0; i < numSelectedStocks; ++i) {
        StockData data;
        if (!fetchStockData(stockData)) {
            std::cout << "Failed to initialize stock.\n";
        }
    }
    
    std::cout << "Initialized stock map.\n";
    return true;

}

bool StockAPI::fetchStockData(std::unordered_map<std::string, StockData>& stockData) {
    std::string url = "https://finnhub.io/api/v1/stock/market/batch?symbols=";
    for (const auto& pair : stockData) {
        const std::string& ticker = pair.first;
        url += ticker + ",";
    }
    url += "&types=quote&token=" + apiKey;

    CURL* curl = curl_easy_init();
    if (curl) {
        std::string response;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "Failed to fetch stock data: " << curl_easy_strerror(res) << std::endl;
            curl_easy_cleanup(curl);
            return false;
        }

        curl_easy_cleanup(curl);

        json jsonData = json::parse(response);

        for (const auto& pair : stockData) {
            const std::string& ticker = pair.first;
            if (jsonData.find(ticker) != jsonData.end()) {
                json quoteData = jsonData[ticker]["quote"];
                StockData data;
                data.ticker = ticker;
                float price = quoteData["latestPrice"];
                while (price < 10000) price *= 10;
                data.price = static_cast<int>(price);
                data.volume = quoteData["latestVolume"];
                // Extract any additional stock data fields as needed

                stockData.emplace(ticker, data);
            }
        }

        return true;
    }

    return false;
}
