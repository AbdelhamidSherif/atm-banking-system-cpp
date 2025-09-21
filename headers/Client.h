#ifndef CLIENT_H
#define CLIENT_H

#include <string>
using namespace std;

// Client structure
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance = 0;
    bool MarkForDelete = false;
};

// Menu options enumeration
enum enMainMenueOptions {
    eQucikWithdraw = 1, 
    eNormalWithDraw = 2, 
    eDeposit = 3,
    eCheckBalance = 4, 
    eExit = 5
};

// Global constants and variables
extern const string ClientsFileName;
extern sClient CurrentClient;

#endif