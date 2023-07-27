#include "StockAPI.h"
#include <iostream>
#include <curl/curl.h>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

// Callback function for curl to write received data
// receive data from the response of an HTTP request made with libcurl and store it in a buffer
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* buffer) {
    size_t totalSize = size * nmemb;
    buffer->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

StockAPI::StockAPI(const std::string& apiKey) : apiKey_(apiKey) {
    // Initialize any necessary variables or configurations
    curl_global_init(CURL_GLOBAL_ALL);
}

bool StockAPI::fetchStockData(std::unordered_map<std::string, StockData>& stockData) {
    std::string url = "https://cloud.iexapis.com/stable/stock/market/batch?symbols=";
    for (const auto& pair : stockData) {
        const std::string& ticker = pair.first;
        url += ticker + ",";
    }
    url += "&types=quote&token=" + apiKey_;

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

        auto floatToFiveDigitInt = [](float value) {
            
        };

        std::string url = "https://cloud.iexapis.com/stable/stock/market/batch?symbols=";
        for (const auto& pair : stockData) {
            const std::string& ticker = pair.first;
            url += ticker + ",";
        }

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
