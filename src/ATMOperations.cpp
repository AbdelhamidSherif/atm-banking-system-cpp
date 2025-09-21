#include "../headers/ATMOperations.h"
#include "../headers/FileManager.h"
#include "../headers/Userlnterface.h"
#include <iostream>

// Transaction processing
bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector<sClient>& vClients)
{
    char Answer = 'n';

    cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        for (sClient& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;
                SaveCleintsDataToFile(ClientsFileName, vClients);
                cout << "\n\nDone Successfully. New balance is: " << C.AccountBalance;

                return true;
            }
        }
    }

    return false;
}

// Quick Withdraw functions
short GetQuickWithDrawAmount(short QuickWithDrawOption)
{
    switch (QuickWithDrawOption)
    {
    case 1: return 20;
    case 2: return 50;
    case 3: return 100;
    case 4: return 200;
    case 5: return 400;
    case 6: return 600;
    case 7: return 800;
    case 8: return 1000;
    default: return 0;
    }
}

void PerfromQuickWithdrawOption(short QuickWithDrawOption)
{
    if (QuickWithDrawOption == 9) // exit 
        return;

    short WithDrawBalance = GetQuickWithDrawAmount(QuickWithDrawOption);

    if (WithDrawBalance > CurrentClient.AccountBalance)
    {
        cout << "\nThe amount exceeds your balance, make another choice.\n";
        cout << "Press Anykey to continue...";
        system("pause>0");
        ShowQuickWithdrawScreen();
        return;
    }

    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, WithDrawBalance * -1, vClients);
    CurrentClient.AccountBalance -= WithDrawBalance;
}

short ReadQuickWithdrawOption()
{
    short Choice = 0;
    while (Choice < 1 || Choice > 9)
    {
        cout << "\nChoose what to do from [1] to [9] ? ";
        cin >> Choice;
    }

    return Choice;
}

void ShowQuickWithdrawScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tQucik Withdraw\n";
    cout << "===========================================\n";
    cout << "\t[1] 20\t\t[2] 50\n";
    cout << "\t[3] 100\t\t[4] 200\n";
    cout << "\t[5] 400\t\t[6] 600\n";
    cout << "\t[7] 800\t\t[8] 1000\n";
    cout << "\t[9] Exit\n";
    cout << "===========================================\n";
    cout << "Your Balance is " << CurrentClient.AccountBalance;

    PerfromQuickWithdrawOption(ReadQuickWithdrawOption());
}

// Normal Withdraw functions
int ReadWithDrawAmont()
{
    int Amount;
    cout << "\nEnter an amount multiple of 5's ? ";

    cin >> Amount;

    while (Amount % 5 != 0)
    {
        cout << "\nEnter an amount multiple of 5's ? ";
        cin >> Amount;
    }
    return Amount;
}

void PerfromNormalWithdrawOption()
{
    int WithDrawBalance = ReadWithDrawAmont();

    if (WithDrawBalance > CurrentClient.AccountBalance)
    {
        cout << "\nThe amount exceeds your balance, make another choice.\n";
        cout << "Press Anykey to continue...";
        system("pause>0");
        ShowNormalWithDrawScreen();
        return;
    }

    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    if (DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, WithDrawBalance * -1, vClients))
    {
        CurrentClient.AccountBalance -= WithDrawBalance;
    }
}

void ShowNormalWithDrawScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tNormal Withdraw Screen\n";
    cout << "===========================================\n";
    PerfromNormalWithdrawOption();
}

// Deposit functions
double ReadDepositAmount()
{
    double Amount;
    cout << "\nEnter a positive Deposit Amount? ";

    cin >> Amount;
    while (Amount <= 0)
    {
        cout << "\nEnter a positive Deposit Amount? ";
        cin >> Amount;
    }
    return Amount;
}

void PerfromDepositOption()
{
    double DepositAmount = ReadDepositAmount();

    vector<sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    if (DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, DepositAmount, vClients))
    {
        CurrentClient.AccountBalance += DepositAmount;
    }
}

void ShowDepositScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tDeposit Screen\n";
    cout << "===========================================\n";
    PerfromDepositOption();
}

// Balance check functions
void ShowCheckBalanceScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tCheck Balance Screen\n";
    cout << "===========================================\n";
    cout << "Your Balance is " << CurrentClient.AccountBalance << "\n";
}