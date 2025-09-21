#include "../headers/Authentication.h"
#include "../headers/FileManager.h"
#include "../headers/Userlnterface.h"
#include <iostream>

bool FinedClientByAccountNumberAndPinCode(string AccountNumber, string PinCode, sClient& Client)
{
    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    for (sClient& C : vClients)
    {
        if ((C.AccountNumber == AccountNumber && C.PinCode == PinCode))
        {
            Client = C;
            return true;
        }
    }

    return false;
}

bool LoadClientInfo(string AccountNumber, string PinCode)
{
    if (FinedClientByAccountNumberAndPinCode(AccountNumber, PinCode, CurrentClient))
        return true;
    else
        return false;
}

void Login()
{
    bool LoginFaild = false;
    string AccountNumber, PinCode;
    
    do
    {
        system("cls");
        cout << "\n---------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n---------------------------------\n";

        if (LoginFaild)
        {
            cout << "Invlaid Account Number/PinCode!\n";
        }

        cout << "Enter Account Number? ";
        cin >> AccountNumber;

        cout << "Enter Pin? ";
        cin >> PinCode;
        LoginFaild = !LoadClientInfo(AccountNumber, PinCode);

    } while (LoginFaild);

    ShowMainMenue();
}