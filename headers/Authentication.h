#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include "Client.h"

// Authentication functions
bool FinedClientByAccountNumberAndPinCode(string AccountNumber, string PinCode, sClient& Client);
bool LoadClientInfo(string AccountNumber, string PinCode);
void Login();

#endif