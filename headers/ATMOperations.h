#ifndef ATMOPERATIONS_H
#define ATMOPERATIONS_H

#include "Client.h"
#include <vector>

// Quick Withdraw functions
short GetQuickWithDrawAmount(short QuickWithDrawOption);
void PerfromQuickWithdrawOption(short QuickWithDrawOption);
short ReadQuickWithdrawOption();
void ShowQuickWithdrawScreen();

// Normal Withdraw functions
int ReadWithDrawAmont();
void PerfromNormalWithdrawOption();
void ShowNormalWithDrawScreen();

// Deposit functions
double ReadDepositAmount();
void PerfromDepositOption();
void ShowDepositScreen();

// Balance check functions
void ShowCheckBalanceScreen();

// Shared transaction function
bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector<sClient>& vClients);

#endif