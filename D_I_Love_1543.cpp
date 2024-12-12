#include <iostream>
#include <vector>
using namespace std;

// Function to count occurrences of the number 1543 in a matrix layer (0-based index)
long long count1543(vector<vector<int> > &v, int layerInd, int n, int m) {
    vector<int> layer;
    
    // Extract the layer elements in a clockwise manner
    // Top row
    for (int i = layerInd; i < m - layerInd; i++) {
        layer.emplace_back(v[layerInd][i]);
    }
    
    // Right column
    for (int i = layerInd + 1; i < n - layerInd; i++) {
        layer.emplace_back(v[i][m - layerInd - 1]);
    }
    
    // Bottom row
    for (int i = m - layerInd - 2; i >= layerInd; i--) {
        layer.emplace_back(v[n - layerInd - 1][i]);
    }
    
    // Left column
    for (int i = n - layerInd - 2; i > layerInd; i--) {
        layer.emplace_back(v[i][layerInd]);
    }
    
    // Count occurrences of 1543 in a circular traversal
    long long cnt = 0;
    int layerSize = layer.size();
    for (int i = 0; i < layerSize; i++) {
        int num = layer[i] * 1000 + layer[(i + 1) % layerSize] * 100 
                + layer[(i + 2) % layerSize] * 10 + layer[(i + 3) % layerSize];
        cnt += (num == 1543);
    }
    return cnt;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        // Initialize the matrix with n rows and m columns
        vector<vector<int> > a(n, vector<int>(m));
        
        // Input the matrix elements
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        
        long long cnt = 0;
        // Traverse each layer up to min(n/2, m/2) layers
        for (int layer = 0; layer < min(n / 2, m / 2); layer++) {
            cnt += count1543(a, layer, n, m);
        }
        
        // Output the count
        cout << cnt << "\n";
    }
    return 0;
}