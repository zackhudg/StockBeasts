#define NOMINMAX
#include <algorithm>
#include "StockAPI.h"
#include <iostream>
#include <string>
#include <curl/curl.h>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* buffer) {
    size_t totalSize = size * nmemb;
    buffer->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

StockAPI::StockAPI(const std::string& apiKey) : apiKey(apiKey) {
    curl_global_init(CURL_GLOBAL_ALL);
}

bool StockAPI::initStockMap(std::unordered_map<std::string, StockData>& stockData, int numRandomStocks) {
    std::string symbolUrl = "http://financialmodelingprep.com/api/v3/stock/list?apikey=" + apiKey;

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

    for (const auto& entry : jsonData) {
        symbols.push_back(entry["symbol"]);
    }

    srand(static_cast<unsigned int>(time(NULL)));
    std::random_shuffle(symbols.begin(), symbols.end());
    int numSelectedStocks = std::min(numRandomStocks, static_cast<int>(symbols.size()));

    for (int i = 0; i < numSelectedStocks; ++i) {
        StockData data;
        if (!fetchStockData(stockData)) {
            std::cout << "Failed to initialize stock.\n";
        }
    }

    return true;
    std::cout << "Initialized stock map.\n";
}

bool StockAPI::fetchStockData(std::unordered_map<std::string, StockData>& stockData) {
    // Adjust this URL and parsing logic based on FMP's API structure
    std::string url = "https://financialmodelingprep.com/api/v3/quote/";
    for (const auto& pair : stockData) {
        const std::string& ticker = pair.first;
        url += ticker + ",";
    }
    url += "?apikey=" + apiKey;

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
                json quoteData = jsonData[ticker];
                StockData data;
                data.ticker = ticker;
                float price = quoteData["price"];
                while (price < 10000) price *= 10;
                data.price = static_cast<int>(price);
                data.volume = quoteData["volume"];
                stockData.emplace(ticker, data);
            }
        }

        return true;
    }

    return false;
}
