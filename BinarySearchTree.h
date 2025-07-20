#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "TreeNode.h"
#include "FileMetaData.h"

class BinarySearchTree {
private:
    TreeNode* root;

public:
    BinarySearchTree() : root(nullptr) {}

    TreeNode* getRoot() const {
        return root;
    }

void inOrderTraversalForFiles(TreeNode* node, FileMetaData* files, int& index, int maxSize) const {
    if (node != nullptr && index < maxSize) {
        inOrderTraversalForFiles(node->getLeft(), files, index, maxSize);
        files[index++] = *(node->getData());
        inOrderTraversalForFiles(node->getRight(), files, index, maxSize);
    }
}

int getAllFiles(FileMetaData* files, int maxSize) const {
    int index = 0;
    inOrderTraversalForFiles(root, files, index, maxSize);
    return index;
}

    void insertFile(FileMetaData* fileData) {
        if (root == nullptr) {
            root = new TreeNode(fileData);
        } else {
            root->insertFile(fileData);
        }
    }

    void inorderTraversal() const {
        if (root != nullptr) {
            root->inorderTraversal();
        } else {
            std::cout << "Tree is empty." << std::endl;
        }
    }

    TreeNode* depthFirstSearch(const std::string& fileName) {
        if (root != nullptr) {
            return root->depthFirstSearch(fileName);
        } else {
            std::cout << "Tree is empty." << std::endl;
            return nullptr;
        }
    }

    void deleteFile(const std::string& fileName) {
        if (root != nullptr) {
            root = root->deleteFile(root, fileName);
        } else {
            std::cout << "Tree is empty." << std::endl;
        }
    }
};
#endif

