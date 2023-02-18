#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include "AVLTree.h"
#include "DataValidation.h"

using namespace std;



int main() {

    // Declaring variables that are going to be used
    int num_lines, n;
    long ID;
    string line, command, name, stringID, space1, space2, questionString, appendString, removeNode, string_n, key;
    AVL myAVL;

    // Gets amount of lines needed to read
    getline(cin, line);
    num_lines = stoi(line);

    // While number of lines is not 0, keep reading lines
    while(num_lines--){

        // Creates a string stream object(sso) and reads in the command
        getline(cin, line);
        stringstream sso(line);
        getline(sso, command, ' ');

        // Checks if the command is valid
        if (commandCheck(command)){
            cout << "unsuccessful" << endl;
            continue;
        }

        // Insert
        if (command == "insert")
        {

            getline(sso, space1, '\"');
            getline(sso, name, '\"');
            name.erase(remove(name.begin(), name.end(), '\"'), name.end());
            getline(sso, space2, ' ');
            getline(sso, stringID, ' ');

            // Determines if ID is 8 characters and if name has valid characters
            if (digitCounter(stringID) || !letterChecker(name))
            {
                cout << "unsuccessful" << endl;
                continue;
            }

            // Tries to insert, if node already exists with ID it prints unsuccessful
            bool insertFlag = false;
            myAVL.insert(stringID, name, insertFlag);

            if (insertFlag)
            {
                cout << "unsuccessful" << endl;
            }

            else
            {
                cout << "successful" << endl;
            }

        }

        // Remove
        if (command == "remove")
        {

            // Checks for valid key length
            getline(sso, removeNode, '\n');
            if (digitCounter(removeNode))
            {
                cout << "unsuccessful" << endl;
                continue;
            }

            // Tries removing, if ID does not exist it prints unsuccessful
            bool flag = false;
            myAVL.removeNode(removeNode, flag);

            if (flag)
            {
                cout << "successful" << endl;
            }

            if (!flag && !digitCounter(removeNode))
            {
                cout << "unsuccessful" << endl;
            }

        }

        // Search
        if (command == "search")
        {

            // Gets either ID or name
            getline(sso, questionString, '\n');

            // Logic for if it is a name
            if (questionString.find('\"') != string::npos)
            {
                questionString.erase(remove(questionString.begin(), questionString.end(), '\"'), questionString.end());
                name = questionString;

                // Checks to make sure name passed in is valid
                if (!letterChecker(name))
                {
                    cout << "unsuccessful" << endl;
                    continue;
                }

                vector<string> matchNodes;
                matchNodes = myAVL.searchName(matchNodes, name);

                // No nodes had the name
                if (matchNodes.empty())
                {
                    cout << "unsuccessful" << endl;
                }

                // Print out node's ID that had the name
                else
                {
                    for (int i = 0; i < matchNodes.size(); i++)
                    {
                        cout << matchNodes[i] << endl;
                    }
                }
            }

            // Logic for if it's and ID
            else
            {

                // Checks to make sure ID is 8 digits
                if (digitCounter(questionString))
                {
                    cout << "unsuccessful" << endl;
                    continue;
                }
                myAVL.searchID(questionString);

            }

        }

        // Prints tree inorder
        if (command == "printInorder"){
            bool flag1 = true;
            myAVL.inorder(flag1);
            cout << endl;
        }

        // Prints tree preorder
        if (command == "printPreorder"){
            bool flag2 = true;
            myAVL.preorder(flag2);
            cout << endl;
        }

        // Prints tree postorder
        if (command == "printPostorder"){
            bool flag3 = true;
            myAVL.postorder(flag3);
            cout << endl;
        }

        // Prints total levels
        if (command == "printLevelCount"){
            cout << myAVL.maxDepth() << endl;

        }

        // Remove Inorder
        if (command == "removeInorder"){

            // Creates a vector of all nodes in the tree
            vector<AVL::TreeNode*> matchNodes = myAVL.returnVector();

            // Reads in what n is and finds what ID is at the nth node
            getline(sso, string_n, '\n');
            n = stoi(string_n);

            bool flag = false;
            // Makes sure n is a valid index for the size of the vector
            if (n < matchNodes.size())
            {
                key = matchNodes[n]->val;
                myAVL.removeNode(key, flag);

                if (flag)
                {
                    cout << "successful" << endl;
                }

                else
                {
                    cout << "unsuccessful" << endl;
                }
            }

            else
            {
                cout << "unsuccessful" << endl;
            }
        }

    }

    return 0;

}
