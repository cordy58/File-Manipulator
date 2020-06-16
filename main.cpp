#include "FileManip.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    FileManip file;
    
    bool run = true;
    string selection = "";
    cout << "FILE MANIPULATOR" << endl << endl;
    while (run == true) {
        cout << "What would you like to do?" << endl;
        cout << "Enter the number to perform the action, enter 0 to quit " << endl;
        cout << "1: Add content to a file" << endl;
        cout << "2: Print a file" << endl;
        cout << "3: Erase a file" << endl;
        cout << "0: Quit program" << endl;
        
        cin >> selection;
        if (selection == "1") {
            file.addContent();
        }
        else if (selection == "2") {
            file.printFile();
        }
        else if (selection == "3") {
            file.clearFile();
        }
        else if (selection == "0") {
            run = false;
        }
        else {
            cout << "Please enter 1, 2, 3, or 0. " << endl;
        }
    }
}
