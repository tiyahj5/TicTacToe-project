//Tiyah Johnson
//LAB 1: CS 511 (Design and Analysis of Algorithms)
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Lomuto partition scheme PowerPoint notes Module 3
int lomutoPartition(int arr[], int lo, int high) {
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = lo - 1; // Place for swapping
    for (int j = lo; j < high; j++) {
        if (arr[j] <= pivot) {
            i++; // Increment the place for swapping
            swap(arr[i], arr[j]); // Swap
        }
    }
    swap(arr[i + 1], arr[high]); // Swap the pivot with the element at i+1
    return i + 1; // Return the partition index
}

// Hoare partition scheme PowerPoint notes Module 3
int hoarePartition(int arr[], int p, int r) {
    int pivot = arr[r]; // Choosing the pivot as the last element
    int i = p - 1;
    int j = r;

    while (true) {
        do {
            i = i + 1;
        } while (arr[i] <= pivot && i < r); // Increment i until arr[i] > pivot
        do {
            j = j - 1;
        } while (arr[j] > pivot && j > p); // Decrement j until arr[j] <= pivot

        if (i < j) {
            swap(arr[i], arr[j]); // Swap arr[i] with arr[j]
        } else {
            if (arr[i] > pivot) {
                swap(arr[i], arr[r]); // Swap arr[i] with the pivot
                return i; // Return partition index
            }
            return r;
        }
    }
}

// Quick Sort function using Lomuto or Hoare partition based on Module 3 Power Point
void quickSort(int arr[], int p, int r, char partitionType) {
    if (p < r) {
        int q; // Partition index
        if (partitionType == 'L') {
            q = lomutoPartition(arr, p, r); // Lomuto Partition
        } else {
            q = hoarePartition(arr, p, r); // Hoare Partition
        }
        quickSort(arr, p, q - 1, partitionType); // Recursively sort the left part
        quickSort(arr, q + 1, r, partitionType); // Recursively sort the right part
    }
}

// Function to generate a random array with values between a and b
void generateRandomArray(int* arr, int n, int a, int b) {
    for (int i = 0; i < n; i++) {
        arr[i] = a + rand() % (b - a + 1); // Random numbers between a and b
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int N, a, b;
    char partitionChoice;

    // Input the size of the array
    cout << "Enter the size of the array (N): ";
    cin >> N;

    // Input the range for random numbers
    cout << "Enter the range for the random numbers (a and b): ";
    cin >> a >> b;

    // Random Number Generator using "srand"
    srand(time(0));

    // Dynamica array
    int* arr = new int[N];

    // Generate random array within range [a, b]
    generateRandomArray(arr, N, a, b);

    // Print unsorted data
    cout << "Unsorted Array: ";
    printArray(arr, N);

    // Choose partition method
    cout << "Enter 'L' for Lomuto Partition or 'H' for Hoare Partition: ";
    cin >> partitionChoice;

    // Call Quick Sort based on the partition choice
    quickSort(arr, 0, N - 1, partitionChoice);

    // Print the sorted data
    cout << "Sorted Array: ";
    printArray(arr, N);
return 0;

}