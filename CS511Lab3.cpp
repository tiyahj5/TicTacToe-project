#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>  
#include <fstream>

using namespace std;

// Function to perform the Floyd-Warshall algorithm
void floydWarshall(const vector<vector<int>>& A, vector<vector<int>>& D, vector<vector<int>>& P, int num_vertices) {
    // Initialize D to A (adjacency matrix) and P to 0
    for (int i = 1; i <= num_vertices; i++) {
        for (int j = 1; j <= num_vertices; j++) {
            D[i][j] = A[i][j];
            if (A[i][j] != INT_MAX && i != j) {
                P[i][j] = i;  // Predecessor of j is i if there is a direct edge
            } else {
                P[i][j] = 0;  // No predecessor
            }
        }
    }

    // Main loop for Floyd-Warshall
    for (int k = 1; k <= num_vertices; k++) {
        for (int i = 1; i <= num_vertices; i++) {
            for (int j = 1; j <= num_vertices; j++) {
                if (D[i][k] != INT_MAX && D[k][j] != INT_MAX) {  // Avoid overflow
                    int dnew = D[i][k] + D[k][j];
                    if (dnew < D[i][j]) {
                        D[i][j] = dnew;  // Update shortest distance (d)
                        P[i][j] = P[k][j];  // Update predecessor (p)
                    }
                }
            }
        }
    }
}

// Function to display the matrix
void displayMatrix(const vector<vector<int>>& matrix, int num_vertices, const string& label) {
    cout << label << ":\n";
    for (int i = 1; i <= num_vertices; i++) {
        for (int j = 1; j <= num_vertices; j++) {
            if (matrix[i][j] == INT_MAX) {
                cout << setw(5) << "INF";
            } else {
                cout << setw(5) << matrix[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    // Adjacency matrix based on the graph in the image
    vector<vector<int>> A = {
        {0, 0, 0, 0, 0},            // Padding row for 1-based indexing
        {0, 0, 50, 30, 15},         // A[1] row
        {0, 5, 0, 15, INT_MAX},     // A[2] row
        {0, INT_MAX, 5, 0, 15},     // A[3] row
        {0, 15, INT_MAX, 5, 0}      // A[4] row
    };

    int num_vertices = 4;  // Number of vertices (indexed from 1 to 4)

    // Distance matrix D and predecessor matrix P
    vector<vector<int>> D(num_vertices + 1, vector<int>(num_vertices + 1, INT_MAX));  
    vector<vector<int>> P(num_vertices + 1, vector<int>(num_vertices + 1, 0));  

    // Call Floyd-Warshall algorithm
    floydWarshall(A, D, P, num_vertices);

    // Display the resulting distance matrix D and predecessor matrix P
    displayMatrix(D, num_vertices, "Distance Matrix (D)");
    displayMatrix(P, num_vertices, "Predecessor Matrix (P)");

    return 0;
//Lab 3  Implementation of Floyd Algorithm 
//Tiyah Johnson
#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>  
#include <fstream> 
using namespace std;

// Function to perform the Floyd-Warshall algorithm
void floydWarshall(const vector<vector<int>>& A, vector<vector<int>>& D, vector<vector<int>>& P, int num_vertices) {
    // Initialize D to A (adjacency matrix) and P to 0
    for (int i = 1; i <= num_vertices; i++) {
        for (int j = 1; j <= num_vertices; j++) {
            D[i][j] = A[i][j];
            if (A[i][j] != INT_MAX && i != j) {
                P[i][j] = i;  // Predecessor of j is i if there is a direct edge
            } else {
                P[i][j] = 0;  // No predecessor
            }
        }
    }

    // Main loop for Floyd-Warshall
    for (int k = 1; k <= num_vertices; k++) {
        for (int i = 1; i <= num_vertices; i++) {
            for (int j = 1; j <= num_vertices; j++) {
                if (D[i][k] != INT_MAX && D[k][j] != INT_MAX) {  // Avoid overflow
                    int dnew = D[i][k] + D[k][j];
                    if (dnew < D[i][j]) {
                        D[i][j] = dnew;  // Update shortest distance (d)
                        P[i][j] = P[k][j];  // Update predecessor (p)
                    }
                }
            }
        }
    }
}

// Function to display the matrix
void displayMatrix(const vector<vector<int>>& matrix, int num_vertices, const string& label) {
    cout << label << ":\n";
    for (int i = 1; i <= num_vertices; i++) {
        for (int j = 1; j <= num_vertices; j++) {
            if (matrix[i][j] == INT_MAX) {
                cout << setw(5) << "INF";
            } else {
                cout << setw(5) << matrix[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    // Adjacency matrix based on the graph in the image
    vector<vector<int>> A = {
        {0, 0, 0, 0, 0},            // Padding row for 1-based indexing
        {0, 0, 50, 30, 15},         // A[1] row
        {0, 5, 0, 15, INT_MAX},     // A[2] row
        {0, INT_MAX, 5, 0, 15},     // A[3] row
        {0, 15, INT_MAX, 5, 0}      // A[4] row
    };

    int num_vertices = 4;  // Number of vertices (indexed from 1 to 4)

    // Distance matrix D and predecessor matrix P
    vector<vector<int>> D(num_vertices + 1, vector<int>(num_vertices + 1, INT_MAX));  
    vector<vector<int>> P(num_vertices + 1, vector<int>(num_vertices + 1, 0));  

    // Call Floyd-Warshall algorithm
    floydWarshall(A, D, P, num_vertices);

    // Display the resulting distance matrix D and predecessor matrix P
    displayMatrix(D, num_vertices, "Distance Matrix (D)");
    displayMatrix(P, num_vertices, "Predecessor Matrix (P)");

    //Save the file as a text file
    // Close the file
    outfile.close();
    
    cout << "Results saved to floyd_warshall_output.txt" << endl;

    return 0;
}