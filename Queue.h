#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include<string>
#include "FileExplorer.h"
using namespace std;

struct HistoryEntry {
    enum OperationType {
        INSERT,
        ACCESS,
        SEARCH,
        SEARCH_AND_READ,
        SEARCH_AND_UPDATE,
        RENAME,
        DELETE
    };

    OperationType operation;
    string fileName;

    HistoryEntry(OperationType op, const string& name) : operation(op), fileName(name) {}
};

template <class T>
class QueueNode {
public:
    T data;
    QueueNode* next;

    QueueNode(const T& value) : data(value), next(nullptr) {}
};

template <class T>
class Queue {
private:
    QueueNode<T>* front;
    QueueNode<T>* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}
    bool isEmpty() const {
        return front == nullptr;
    }

    void enqueue(const T& value) {
        QueueNode<T>* newNode = new QueueNode<T>(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cerr << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        QueueNode<T>* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    const T& getFront() const {
        if (isEmpty()) {
            throw out_of_range("Queue is empty.");
        }

        return front->data;
    }

    void display() const {
        QueueNode<T>* current = front;
        while (current != nullptr) {
            switch (current->data.operation) {
                case HistoryEntry::INSERT:
                    cout << "Inserted file: " << current->data.fileName << endl;
                    break;
                case HistoryEntry::ACCESS:
                    cout << "Accessed file: " << current->data.fileName << endl;
                    break;
                case HistoryEntry::SEARCH:
                    cout << "Searched for file: " << current->data.fileName << endl;
                    break;
                case HistoryEntry::SEARCH_AND_READ:
                    cout << "Searched and read file: " << current->data.fileName << endl;
                    break;
                case HistoryEntry::SEARCH_AND_UPDATE:
                    cout << "Searched and updated file: " << current->data.fileName << endl;
                    break;
                case HistoryEntry::RENAME:
                    cout << "Renamed file: " << current->data.fileName << endl;
                    break;
                case HistoryEntry::DELETE:
                    cout << "Deleted file: " << current->data.fileName << endl;
                    break;
                default:
                    cerr << "Unknown operation type in history." << endl;
            }

            current = current->next;
        }
    }
};

#endif
