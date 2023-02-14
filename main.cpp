#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include "AVLTree.h"
#include "DataValidation.h"

using namespace std;



int main() {
    int num_lines;
    long ID;
    string line, command, name, stringID, space1, space2, questionString, appendString;
    AVL myAVL;




    getline(cin, line);
    num_lines = stoi(line);
    while(num_lines--){
        getline(cin, line);
        stringstream sso(line);
        getline(sso, command, ' ');
        if (commandCheck(command)){
            cout << "unsuccessful" << endl;
            continue;
        }

        if (command == "insert"){
            getline(sso, space1, '\"');
            getline(sso, name, '\"');
            name.erase(remove(name.begin(), name.end(), '\"'), name.end());
            getline(sso, space2, ' ');
            getline(sso, stringID, ' ');
            ID = stol(stringID);

            if (digitCounter(stringID) || !letterChecker(name)){
                cout << "unsuccessful" << endl;
                continue;
            }

            myAVL.insert(stringID, name);

        }

        if (command == "remove"){

        }

        if (command == "search"){


            getline(sso, questionString, '\n');
            if (questionString.find('\"') != string::npos)
            {
                questionString.erase(remove(questionString.begin(), questionString.end(), '\"'), questionString.end());
                name = questionString;

                vector<string> matchNodes;
                matchNodes = myAVL.searchName(matchNodes, name);

                if (matchNodes.empty())
                {
                    cout << "unsuccessful" << endl;
                }

                else
                {
                    for (int i = 0; i < matchNodes.size(); i++)
                    {
                        if (i != 0)
                        {
                            cout << ", ";
                        }
                        cout << matchNodes[i];
                    }
                    cout << endl;
                }
            }

            else
            {
                myAVL.searchID(questionString);
            }

        }

        if (command == "printInorder"){
            myAVL.inorder();
        }

        if (command == "printPreorder"){
            myAVL.preorder();
        }

        if (command == "printPostorder"){
            myAVL.postorder();
        }

        if (command == "printLevelCount"){
            cout << myAVL.maxDepth() << endl;

        }

        if (command == "removeInorder"){

        }





    }
//    cout << command << endl;
//    cout << name << endl;
//    cout << ID << endl;

    return 0;
}
