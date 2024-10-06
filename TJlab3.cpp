//Lab 3  Implementation of Floyd Algorithm 
//Tiyah Johnson
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();  


void floydAlg(vector<vector<int>>& aMatrix, int n, vector<vector<int>>& D, vector<vector<int>>& P) {
   
    D = aMatrix;
    P = vector<vector<int>>(n, vector<int>(n, 0));

    // Floyd Algorithm 
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != k && j != k && D[i][k] != INF && D[k][j] != INF) {  // Check for valid paths
                    int dNew = D[i][k] + D[k][j];
                    if (dNew < D[i][j]) {
                        D[i][j] = dNew;
                        P[i][j] = k + 1;
                    }
                }
            }
        }
    }
}

//Display Function
void display(const vector<vector<int>>& matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == INF) {
                cout << "INF" << "\t";
            } else {
                cout << matrix[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;

   cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> aMatrix(n, vector<int>(n));

    //Put 5000 for inf and copy matrix 
    cout << "Enter numbers for adjacency matrix " << endl;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> aMatrix[i][j];
        }
    }

    vector<vector<int>> D, P;

    floydAlg(aMatrix, n, D, P);


    cout << "Distance Matrix (D):" << endl;
    display(D, n);

    cout << "\nPredecessor Matrix (P):" << endl;
    display(P, n);

    return 0;
}