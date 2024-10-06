//Tiyah Johnson
//lab 3 

#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>  // For INT_MAX

using namespace std;

// Function to perform the Floyd-Warshall algorithm
void floydWarshall(const vector<vector<int>>& A, vector<vector<int>>& D, vector<vector<int>>& P, int num_vertices) {
    // Initialize D to A (adjacency matrix) and P to direct predecessors
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
                if (D[i][k] != INT_MAX && D[k][j] != INT_MAX) { 
                    int dnew = D[i][k] + D[k][j];
                    if (dnew < D[i][j]) {
                        D[i][j] = dnew;  // Update shortest distance (d)
                        P[i][j] = k;  // Update predecessor (p) to k, the intermediate node
                    }
                }
            }
        }
    }
}

// Function to display the matrix on the console
void displayMatrix(const vector<vector<int>>& matrix, int num_vertices, const string& label) {
    cout << label << ":\n";
    for (int i = 1; i <= num_vertices; i++) {
        for (int j = 1; j <= num_vertices; j++) {
            if (matrix[i][j] == INT_MAX) {  // Replace large values (INT_MAX) with "INF"
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
    int num_vertices = 4;

    // Adjacency matrix with specified values
    vector<vector<int>> A = {
        {0, 0, 0, 0, 0},             // Padding row for 1-based indexing
        {0, 0, 5, INT_MAX, INT_MAX},         // Row for vertex 1
        {0, 50, 0, 15, 5},           // Row for vertex 2
        {0, 30, INT_MAX, 0, 15},      // Row for vertex 3
        {0, 15, INT_MAX, 5, 0}        // Row for vertex 4
    };

    // Distance matrix D and predecessor matrix P
    vector<vector<int>> D(num_vertices + 1, vector<int>(num_vertices + 1, INT_MAX));  
    vector<vector<int>> P(num_vertices + 1, vector<int>(num_vertices + 1, 0));  

    // Floyd-Warshall algorithm
    floydWarshall(A, D, P, num_vertices);

    // Display the distance matrix (D) and predecessor matrix (P)
    displayMatrix(D, num_vertices, "Distance Matrix (D)");
    displayMatrix(P, num_vertices, "Predecessor Matrix (P)");

    return 0;
}
