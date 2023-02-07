#include <iostream>
#include <string>
#include <sstream>
using namespace std;


bool commandCheck(string command){
    if (command == "insert" || command == "remove" || command == "search" || command ==   )
}

// Function for verifying if ID is 8 digits
bool digitCounter(long ID) {
    int count = 0;
    while (ID != 0) {
        ID = ID / 10;
        count++;

        // This will save some time if a larger number is passed in for ID
        if (count == 9){
            break;
        }
    }

    if (count != 8){
        return true;
    }

    return false;


}



int main() {
    int num_lines;
    long ID;
    string line, command, name, stringID;
    getline(cin, line);
    num_lines = stoi(line);
    while(num_lines--){
        getline(cin, line);
        stringstream sso(line);
        getline(sso, command, ' ');
        getline(sso, name, ' ');
        getline(sso, stringID, ' ');
        ID = stol(stringID);

        if (digitCounter(ID)){
            cout << "unsuccessful" << endl;
        }

        else {
            cout << command << endl;
            cout << name << endl;
            cout << ID << endl;
        }




    }
    return 0;
}
