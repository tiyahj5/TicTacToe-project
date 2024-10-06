#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function prototypes for quickSort and Hoare and lomuto
void quickSort(vector<int>& arr, int low, int high, char partitionType);
int hoarePartition(vector<int>& arr, int low, int high);
int lomutoPartition(vector<int>& arr, int low, int high);

// Quick Sort function implementation
void quickSort(vector<int>& arr, int low, int high, char partitionType) {
    if (low < high) {
        int pivotIndex;
        if (partitionType == 'H') {
            pivotIndex = hoarePartition(arr, low, high);
            quickSort(arr, low, pivotIndex, partitionType);
            quickSort(arr, pivotIndex + 1, high, partitionType);
        } else {
            pivotIndex = lomutoPartition(arr, low, high);
            quickSort(arr, low, pivotIndex - 1, partitionType);
            quickSort(arr, pivotIndex + 1, high, partitionType);
        }
    }
}

// Hoare partition scheme
int hoarePartition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j) {
            return j;
        }
        swap(arr[i], arr[j]);
    }
}

// Lomuto partition scheme
int lomutoPartition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Main function
int main() {
    srand(time(0));
    int n;
    char partitionType;

//Output size of the array
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter partition type (H for Hoare, L for Lomuto): ";
    cin >> partitionType;

//Random numbers between 0 and 99
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, n - 1, partitionType);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}