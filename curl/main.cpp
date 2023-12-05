#include "checker.h"

int main() {
    setlocale(0, "");

    std::ifstream proxyfile("proxy_list1.txt");
    std::string key = "yb0r04-06c337-0644n8-750231";
    std::string outputfilename = "proxy_info.txt";

    std::ofstream outputfile(outputfilename.c_str());

    if (!proxyfile.is_open()) {
        std::cerr << "cannot open file with proxy servers" << std::endl;
        return 1;
    }

    if (!outputfile.is_open()) {
        std::cerr << "cannot open file to write proxy info" << std::endl;
        proxyfile.close();
        return 1;
    }

    std::string proxy;

    while (std::getline(proxyfile, proxy)) {
        std::string ip = proxy.substr(0, proxy.find(':'));
        int port = std::stoi(proxy.substr(proxy.find(':') + 1));

        checkProxyInfo(ip, port, key, outputfile);
    }

    proxyfile.close();
    outputfile.close();

    return 1;
}