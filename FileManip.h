#ifndef FILE_MANIP_H
#define FILE_MANIP_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class FileManip {
private:
    string fileName;
public:
    FileManip() : fileName("") {};
    ~FileManip() {};
    
    void addContent() {
        cout << "Specify the file you would like to add to: ";
        cin >> fileName;
        cout << endl;
        ofstream outFile;
        outFile.open(fileName, ios::app);
        try {
            if (outFile.is_open()) {
                cout << "Type what you would like to add to the file: ";
                string content;
                cin.ignore();
                getline(cin, content);
                
                outFile << content;
                outFile.close();
            }
            else throw string("The file didn't open. ");
        } catch (string error) {
            cout << error << endl;
        }
        
    };
    
    void printFile() {
        cout << "Which file would you like to print from? " << endl;
        cin >> fileName;
        cout << endl;
        
        ifstream inFile(fileName);
        try {
            if (inFile.is_open()) {
                cout << fileName << " says: " << endl << endl;
                ostringstream fileContents;
                string line;
                cin.ignore();
                while (getline(inFile, line)) {
                    fileContents << line << endl;
                }
                cout << fileContents.str();
                inFile.close();
            }
            else throw string("The file didn't open. Check to see if that file exists.");
        } catch (string error) {
            cout << error << endl;
        }
    };
    
    void clearFile() {
        cout << "Which file would you like to clear?" << endl;
        cin >> fileName;
        cout << endl;
        
        ofstream clear;
        clear.open(fileName, std::ofstream::out | std::ofstream::trunc);
        clear.close();
    };
    
};

#endif
