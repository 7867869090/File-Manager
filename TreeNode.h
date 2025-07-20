#ifndef TREE_NODE_H
#define TREE_NODE_H

#include "FileMetaData.h"

class TreeNode {

private:
    FileMetaData* data;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode(FileMetaData* fileData)
        : data(fileData), left(nullptr), right(nullptr) {}

    FileMetaData* getData() const {
        return data;
    }

    void setData(FileMetaData* fileData) {
        data = fileData;
    }

    TreeNode* getLeft() const {
        return left;
    }

    void setLeft(TreeNode* leftNode) {
        left = leftNode;
    }

    TreeNode* getRight() const {
        return right;
    }

    void setRight(TreeNode* rightNode) {
        right = rightNode;
    }

    void insertFile(FileMetaData* fileData) {
        if (fileData->getFileSize() < data->getFileSize()) {
            if (left == nullptr) {
                left = new TreeNode(fileData);
            } else {
                left->insertFile(fileData);
            }
        } else if (fileData->getFileSize() > data->getFileSize()) {
            if (right == nullptr) {
                right = new TreeNode(fileData);
            } else {
                right->insertFile(fileData);
            }
        }
    }

    void inorderTraversal() const {
        if (left != nullptr) {
            left->inorderTraversal();
        }

        data->displayDataInformation();

        if (right != nullptr) {
            right->inorderTraversal();
        }
    }

    TreeNode* depthFirstSearch(const std::string& fileName) {
        if (fileName == data->getFileName()) {
            return this;
        }

        TreeNode* result = nullptr;

        if (fileName < data->getFileName() && left != nullptr) {
            result = left->depthFirstSearch(fileName);
        } else if (fileName > data->getFileName() && right != nullptr) {
            result = right->depthFirstSearch(fileName);
        }

        return result;
    }

    TreeNode* deleteFile(TreeNode* root, const std::string& fileName) {
        if (root == nullptr) {
            return root;
        }

        if (fileName < root->getData()->getFileName()) {
            root->setLeft(deleteFile(root->getLeft(), fileName));
        } else if (fileName > root->getData()->getFileName()) {
            root->setRight(deleteFile(root->getRight(), fileName));
        } else {
            if (root->getLeft() == nullptr) {
                TreeNode* temp = root->getRight();
                delete root;
                return temp;
            } else if (root->getRight() == nullptr) {
                TreeNode* temp = root->getLeft();
                delete root;
                return temp;
            }

            TreeNode* temp = findMin(root->getRight());
            root->setData(temp->getData());
            root->setRight(deleteFile(root->getRight(), temp->getData()->getFileName()));
        }
        return root;
    }

private:
    TreeNode* findMin(TreeNode* node) {
        while (node->getLeft() != nullptr) {
            node = node->getLeft();
        }
        return node;
    }
};
#endif
