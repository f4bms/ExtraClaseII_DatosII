#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <iostream>
#include <vector>
using namespace std;

class BubbleSort {
public:
    // Static method to perform bubble sort on a vector
    static void sort(vector<int>& arr) {
        int size = arr.size();  // Obtener el tamaño del vector
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    // Swap the elements
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    // Static method to print the vector
    static void printArray(const vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
#endif //BUBBLESORT_H