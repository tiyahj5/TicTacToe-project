//Tiyah Johnson
//Homework HOMEWORK 3
#include <iostream>
#include <fstream> 
using namespace std;

//Recursive function for Insertion Sort
//A is the array N is the total no of data
void insertionSortRecursive(int arr[], int N) {
    // Base case: if the array has 1 or no elements, return
    if (N <= 1) {
        return;
    }

    // Recursive call for first N-1 elements
    insertionSortRecursive(arr, N - 1);

    // Insert the last element at its correct position in sorted part
    int key = arr[N - 1];
    int i = N - 2;

    // Shift elements of sorted part of array that are greater than key
    while (i >= 0 && arr[i] > key) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = key;
}

int main() {
    int N;
    // Input the number of elements
    cout << "Enter the number of elements: ";
    cin >> N;

    // Declare an array of size N
    int arr[N];
    
    // Input N elements from the user
    cout << "Enter " << N << " integers: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Call the recursive insertion sort function
    insertionSortRecursive(arr, N);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Export the sorted array to a text file
    // Create a file called "sorted_data.txt"
    ofstream outFile("sorted_data.txt"); 
    if (outFile.is_open()) {
        outFile << "Sorted array: ";
        for (int i = 0; i < N; i++) {
            outFile << arr[i] << " ";
        }
        outFile << endl;
        outFile.close();  // Close the file after writing
        cout << "Sorted data has been exported to 'sorted_data.txt'." << endl;
    } else {
        cout << "Unable to open file for writing." << endl;
    }

    return 0;
}










