#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Fungsi untuk mencetak jalur terpendek
void printPath(const vector<int>& path) {
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i != path.size() - 1)
            cout << "--->";
    }
    cout << "--->" << path[0] << endl;
}

// Fungsi untuk mencetak matriks biaya
void printCostMatrix(const vector<vector<int>>& costMatrix) {
    for (int i = 0; i < costMatrix.size(); ++i) {
        for (int j = 0; j < costMatrix[i].size(); ++j) {
            cout << "\t" << costMatrix[i][j];
        }
        cout << endl;
    }
}

// Fungsi untuk mencari jalur terpendek menggunakan algoritma penjelajahan semua kemungkinan (brute force)
int findShortestPath(const vector<vector<int>>& costMatrix, vector<int>& path, vector<bool>& visited, int currentCity, int n, int count, int cost, int& minCost) {
    if (count == n && costMatrix[currentCity][0] != 0) {
        minCost = min(minCost, cost + costMatrix[currentCity][0]);
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        if (visited[i] == false && costMatrix[currentCity][i] != 0) {
            visited[i] = true;
            path[count] = i;
            findShortestPath(costMatrix, path, visited, i, n, count + 1, cost + costMatrix[currentCity][i], minCost);
            visited[i] = false;
        }
    }
    return minCost;
}

int main() {
    int n;
    cout << "Masukkan Jumlah Kota: ";
    cin >> n;

    vector<vector<int>> costMatrix(n, vector<int>(n, 0));

    cout << "Nilai Cost Matrix" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Cost Element Baris ke-: " << i + 1 << endl;
        for (int j = 0; j < n; ++j) {
            cin >> costMatrix[i][j];
        }
    }

    cout << "Cost List:" << endl;
    printCostMatrix(costMatrix);

    vector<int> path(n, -1);
    vector<bool> visited(n, false);
    int minCost = INT_MAX;

    visited[0] = true;
    path[0] = 0;

    cout << endl << "Jalur Terpendek:" << endl;
    findShortestPath(costMatrix, path, visited, 0, n, 1, 0, minCost);
    printPath(path);

    cout << endl << "Minimum Cost: " << minCost << endl;

    return 0;
}