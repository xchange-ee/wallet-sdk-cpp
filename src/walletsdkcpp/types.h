#ifndef WALLET_SDK_CPP_TYPES_H
#define WALLET_SDK_CPP_TYPES_H

#include <string>
#include <vector>

struct DepositItem
{
    int ID;
    std::string Address;
    std::string Amount;
    std::string Blockhash;
    int Confirmations;
    int WalletID;
    int CompanyID;
    std::string Txid;
    std::string Currency;
    std::string Status;
};

struct DepositPagesQuery
{
    int PerPage;
    int Page;
    DepositQuery Query;
    DepositOrderBy OrderBy;
};

struct DepositQuery
{
    int To;
    int From;
    int UpdatedTo;
    int UpdatedFrom;
    std::string Currency;
    int CompanyID;
    int WalletID;
};
struct DepositOrderBy
{
    std::string Field;
    std::string Direction;
};

struct DepositPagesResponse
{
    std::vector<DepositItem> Data;
    int Page;
    int Pages;
    int Total;
};
#endif