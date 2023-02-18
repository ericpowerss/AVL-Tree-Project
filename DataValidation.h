
#ifndef AVL_TREE_DATAVALIDATION_H
#define AVL_TREE_DATAVALIDATION_H

#include<iostream>
using namespace std;

// Verifies if the command is valid
bool commandCheck(const string& command)
{

    if (command == "insert" || command == "remove" || command == "search" || command == "printInorder" || command == "printPreorder" || command == "printPostorder" || command == "removeInorder" || command == "printLevelCount")
    {
        return false;
    }

    return true;

}

// Function for verifying if ID is 8 digits
bool digitCounter(const string& stringID)
{

    if (stringID.length() == 8)
    {
        return false;
    }

    return true;

}

// Checks for letters a-z, A-Z, and spaces
bool letterChecker(const string& name)
{
    return name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") == string::npos;
}

// Used with search to determine if string that follows command is an ID or a name
bool nameTest(const string& name)
{
    return name.find_first_not_of('\"') == string::npos;
}

#endif //AVL_TREE_DATAVALIDATION_H
