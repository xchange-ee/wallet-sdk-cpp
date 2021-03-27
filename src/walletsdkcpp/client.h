#ifndef WALLET_SDK_CPP_CLIENT_H
#define WALLET_SDK_CPP_CLIENT_H

#include <pistache/client.h>
#include <pistache/http.h>
#include <pistache/net.h>

using namespace Pistache;
using namespace Pistache::Http;

namespace walletsdkcpp
{
    class WalletClient
    {
    private:
        Http::Client httpclient;
        std::string Url;
        std::string token;
        std::string env;

    public:
        WalletClient(const std::string &token, const std::string &env);
        ~WalletClient();
        std::string Request(const std::string method, std::string action, std::string body);
    };

}

#endif