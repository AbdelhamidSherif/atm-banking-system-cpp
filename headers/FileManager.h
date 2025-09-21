#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Client.h"
#include <vector>
#include <fstream>

// File operations
vector<sClient> LoadClientsDataFromFile(string FileName);
vector<sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients);

// Data conversion functions
sClient ConvertLineToRecord(string Line, string Seperator = "#//#");
string ConvertRecordToLine(sClient Client, string Seperator = "#//#");

#endif