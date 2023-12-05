#pragma once

#define CURL_STATICLIB

#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>
#include "rapidjson/document.h"

struct MemoryStruct {
    char* memory;
    size_t size;
};

static size_t WriteMemoryCallback(void* contents, size_t size, size_t nmemb, void* userp);

bool checkProxy(const std::string& ip, int port, const std::string& targetURL, double& responseTime, std::string type);

void checkProxyInfo(const std::string& ip, int port, const std::string& key, std::ofstream& outputFile);

