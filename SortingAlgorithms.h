// SortingAlgorithms.h
#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include "FileMetaData.h"
template <class T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
int partition(T arr[], int low, int high) {
    std::string pivotKey = arr[high].getFileName();
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].getFileName() < pivotKey) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}


template <class T>
void quickSort(T arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

#endif // SORTING_ALGORITHMS_H
