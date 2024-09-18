#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <vector>

using namespace std;

class MergeSort {
public:
    // Public method to sort the vector using merge sort
    static void sort(vector<int>& arr) {
        if (arr.size() > 1) {
            mergeSort(arr, 0, arr.size() - 1);
        }
    }

    // Public method to print the vector
    static void printArray(const vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

private:
    // Recursive method to divide the vector and sort
    static void mergeSort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            // Recursively sort both halves
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            // Merge the sorted halves
            merge(arr, left, mid, right);
        }
    }

    // Method to merge two sorted subarrays
    static void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);

        // Copy data to temp vectors L[] and R[]
        for (int i = 0; i < n1; ++i)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        // Merge the temp vectors back into arr[left..right]
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                ++i;
            } else {
                arr[k] = R[j];
                ++j;
            }
            ++k;
        }

        // Copy the remaining elements of L[], if any
        while (i < n1) {
            arr[k] = L[i];
            ++i;
            ++k;
        }

        // Copy the remaining elements of R[], if any
        while (j < n2) {
            arr[k] = R[j];
            ++j;
            ++k;
        }
    }
};

#endif //MERGESORT_H
