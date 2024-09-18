#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <iostream>
#include <vector>
using namespace std;

class SelectionSort {
public:
    static void sort(vector<int>& arr) {
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

    static void printArray(const vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
#endif //SELECTIONSORT_H
