#ifndef FILE_EXPLORER_H
#define FILE_EXPLORER_H

#include "BinarySearchTree.h"
#include "SortingAlgorithms.h"
#include<string>
#include "Queue.h"

using namespace std;

class FileExplorer {
private:
    BinarySearchTree bst;
    Queue<HistoryEntry> historyQueue;

public:
void insertFile(const string& fileName, int fileSize) {
    TreeNode* existingNode = bst.depthFirstSearch(fileName);
    if (existingNode != nullptr) {
        std::cout << "File with the same name already exists. Please choose a different name." << std::endl;
        return;
    }
    else{
    string contentOption;
    cout << "Do you want to add content? (yes/no): ";
    cin >> contentOption;

    string content;

    if (contentOption == "yes") {
        cin.ignore();
        cout << "Enter file content: ";
        getline(cin, content);
    }

    FileMetaData* fileData = new FileMetaData(fileName, fileSize, time(nullptr));

    if (!content.empty()) {
        fileData->setContent(content);
    }

    bst.insertFile(fileData);

    historyQueue.enqueue({HistoryEntry::INSERT, fileName});
    }

}

    void accessFile(const string& fileName) {
        TreeNode* accessedNode = bst.depthFirstSearch(fileName);
        if (accessedNode != nullptr) {
            cout << "Accessed File: ";
            accessedNode->getData()->displayDataInformation();

            TreeNode* nextNode = accessedNode->getRight();
            if (nextNode != nullptr) {
                cout << "Next File to Access: ";
                nextNode->getData()->displayDataInformation();
            } else {
                cout << "No more files to access." << endl;
            }

            historyQueue.enqueue({HistoryEntry::ACCESS, fileName});
        } else {
            cout << "File not found." << endl;
        }


    }

    void searchFile(const string& fileName) {
        TreeNode* searchedNode = bst.depthFirstSearch(fileName);
        if (searchedNode != nullptr) {
            cout << "File Found: ";
            searchedNode->getData()->displayDataInformation();
        } else {
            cout << "File not found." << endl;
        }
                historyQueue.enqueue({HistoryEntry::SEARCH, fileName});

    }

    void searchAndReadFile(const string& fileName) {
        accessFile(fileName);
                historyQueue.enqueue({HistoryEntry::SEARCH_AND_READ, fileName});

    }

void searchAndUpdateFile(const string& fileName) {
    TreeNode* updatedNode = bst.depthFirstSearch(fileName);
    if (updatedNode != nullptr) {
        cout << "Current File Content: " << updatedNode->getData()->getContent() << endl;

        int updateOption;
        cout << "Choose an update option:" << endl;
        cout << "1. Add content" << endl;
        cout << "2. Remove content between specified words" << endl;
        cout << "Enter your choice: ";
        cin >> updateOption;

        cin.ignore();

        if (updateOption == 1) {
            string contentToAdd;
            cout << "Enter content to add: ";
            getline(cin, contentToAdd);

            cout << "Do you want to add new data(Existing will be deleted) or append to the existing line? (new/append): ";
            string addOption;
            cin >> addOption;

            if (addOption == "append") {
                updatedNode->getData()->appendContentWithSpace(contentToAdd);
            } else {
                updatedNode->getData()->setContent(contentToAdd);
            }

            cout << "Content added successfully." << endl;
        } else if (updateOption == 2) {
            string startWord, endWord;
            cout << "Enter the starting word: ";
            cin >> startWord;
            cout << "Enter the ending word: ";
            cin >> endWord;

            updatedNode->getData()->removeContentBetweenWords(startWord, endWord);

            cout << "Content removed successfully." << endl;
        } else {
            cout << "Invalid option. No updates applied." << endl;
        }

        historyQueue.enqueue({HistoryEntry::SEARCH_AND_UPDATE, fileName});
    } else {
        cout << "File not found." << endl;
    }
}



    void renameFile(const string& oldFileName, const string& newFileName) {
        TreeNode* renamedNode = bst.depthFirstSearch(oldFileName);
        if (renamedNode != nullptr) {
            renamedNode->getData()->setFileName(newFileName);

            historyQueue.enqueue({HistoryEntry::RENAME, oldFileName});
        } else {
            cout << "File not found." << endl;
        }
    }

    void deleteFile(const string& fileName) {
        bst.deleteFile(fileName);

        historyQueue.enqueue({HistoryEntry::DELETE, fileName});
    }

    void displayFiles() const {
        cout << "Current Files in the File Explorer:" << endl;
        bst.inorderTraversal();
    }

    void displayHistory() const {
        cout << "File Explorer History:" << endl;
        historyQueue.display();
    }
void sortFiles() {
    const int MAX_FILES = 100;
    FileMetaData files[MAX_FILES];

    int numFiles = bst.getAllFiles(files, MAX_FILES);


    quickSort(files, 0, numFiles - 1);

    cout << "Sorted Files:" << endl;
    for (int i = 0; i < numFiles; ++i) {
        files[i].displayDataInformation();
    }
}


};
#endif
