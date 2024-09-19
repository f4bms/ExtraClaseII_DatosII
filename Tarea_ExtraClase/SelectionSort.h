#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class SelectionSort {
public:
    static void sort(vector<T>& arr) {
        int size = arr.size();
        for (int i = 0; i < size - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < size; ++j) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    }

    static void printArray(const vector<T>& arr) {
        for (const T& elem : arr) {
            cout << elem << " ";
        }
        cout << endl;
    }
};

#endif // SELECTIONSORT_H
