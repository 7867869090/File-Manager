#include <iostream>
#include<string>
#include "FileExplorer.h"

using namespace std;

int main() {
    FileExplorer fileExplorer;

    while (true) {
        cout << "File Explorer Menu:" << endl;
        cout << "1. Insert File" << endl;
        cout << "2. Access File" << endl;
        cout << "3. Search File" << endl;
        cout << "4. Search and Read File" << endl;
        cout << "5. Search and Update File" << endl;
        cout << "6. Rename File" << endl;
        cout << "7. Delete File" << endl;
        cout << "8. Display Files" << endl;
        cout << "9. Display History" << endl;
        cout << "10. Sort Files" << endl;
        cout << "0. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string fileName;
                int fileSize;
                cout << "Enter file name: ";
                getline(cin,fileName);
                cout << "Enter file size: ";
                cin >> fileSize;
                fileExplorer.insertFile(fileName, fileSize);
                break;
            }
            case 2: {
                string fileName;
                cout << "Enter file name to access: ";
                getline(cin,fileName);
                fileExplorer.accessFile(fileName);
                break;
            }
            case 3: {
                string fileName;
                cout << "Enter file name to search: ";
                getline(cin,fileName);
                fileExplorer.searchFile(fileName);
                break;
            }
            case 4: {
                string fileName;
                cout << "Enter file name to read: ";
                getline(cin,fileName);
                fileExplorer.searchAndReadFile(fileName);
                break;
            }
            case 5: {
                string fileName;
                cout << "Enter file name to update: ";
                getline(cin,fileName);
                fileExplorer.searchAndUpdateFile(fileName);
                break;
            }
            case 6: {
                string oldFileName, newFileName;
                cout << "Enter old file name: ";
                getline(cin,oldFileName);
                cout << "Enter new file name: ";
                getline(cin,newFileName);
                fileExplorer.renameFile(oldFileName, newFileName);
                break;
            }
            case 7: {
                string fileName;
                cout << "Enter file name to delete: ";
                getline(cin,fileName);
                fileExplorer.deleteFile(fileName);
                break;
            }
            case 8:
                fileExplorer.displayFiles();
                break;
            case 9:
                fileExplorer.displayHistory();
                break;
            case 10:
                fileExplorer.sortFiles();
                break;
            case 0:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
