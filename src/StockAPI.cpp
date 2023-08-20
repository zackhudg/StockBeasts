#define NOMINMAX
#include <algorithm>
#include "StockAPI.h"
#include <string>
#include <curl/curl.h>
#include "nlohmann/json.hpp"
#include <iostream>
#include <fstream>

using json = nlohmann::json;

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* buffer) {
    size_t totalSize = size * nmemb;
    buffer->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

StockAPI::StockAPI(const std::string& apiKey) : apiKey(apiKey) {
    curl_global_init(CURL_GLOBAL_ALL);
}

bool StockAPI::initStockMap(std::unordered_map<std::string, StockData>& stockData) {
#ifdef _DEBUG
    std::cout << "Init Stock Map...\n";
#endif
    std::ifstream inputFile("../SP500.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    std::string ticker;
    while (std::getline(inputFile, ticker)) {
        stockData.emplace(ticker, StockData());  // Insert with default StockData
    }

    inputFile.close();

    if (!fetchStockData(stockData)) {
        std::cout << "Failed to initialize stock.\n";
        return false;
    }

    return true;
#ifdef _DEBUG
    std::cout << "Initialized stock map.\n";
#endif
    
}

bool StockAPI::fetchStockData(std::unordered_map<std::string, StockData>& stockDataMap) {
#ifdef _DEBUG
    std::cout << "Fetching Stock Data...\n";
#endif

    // Adjust this URL and parsing logic based on FMP's API structure
    std::string url = "https://financialmodelingprep.com/api/v3/quote/";
    for (const auto& pair : stockDataMap) {
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

        for (const auto& quoteData : jsonData) {
            if (!(quoteData.contains("symbol") && !quoteData["symbol"].is_null() &&
                quoteData.contains("price") && !quoteData["price"].is_null() &&
                quoteData.contains("volume") && !quoteData["volume"].is_null() &&
                quoteData.contains("avgVolume") && !quoteData["avgVolume"].is_null())) {
                continue;
            }
            const std::string& ticker = quoteData["symbol"];
            StockData stockData;
            stockData.ticker = ticker;
            float price = quoteData["price"];
            while (price < 10000) price *= 10;
            int volume = quoteData["volume"];
            int avgVolume = quoteData["avgVolume"];
            stockData.price = static_cast<int>(price);
            stockData.volume = volume;
            stockData.volumeDiff = (volume - avgVolume);
            stockDataMap[ticker] = stockData;
        }

        return true;
    }

    return false;
}
