#include "client.h"
#include <pistache/client.h>
#include <pistache/http.h>
#include <pistache/net.h>

using namespace Pistache;
using namespace Pistache::Http;
using namespace walletsdkcpp;

WalletClient::WalletClient(const std::string &token, const std::string &env) : Url(env == "develop" ? "http://api.sandbox.sc.xchange.ee/node/v1" : "http://api.sc.xchange.ee/node/v1"), env(env), token(token)
{
    auto opts = Http::Client::options().threads(1).maxConnectionsPerHost(8);
    httpclient.init(opts);
}

WalletClient::~WalletClient()
{
}

std::string WalletClient::Request(const std::string method, std::string action, std::string body)
{
    auto contentType = Http::Header::ContentType("application/json");
    auto autorization = Http::Header::Authorization("Bearer " + token);
    auto resp = httpclient.post(Url).header<Http::Header::ContentType>(contentType).header<Http::Header::Authorization>(autorization).body(body).send();
}