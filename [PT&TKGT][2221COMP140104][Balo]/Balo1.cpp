#include <iostream>
#include <vector>

using namespace std;

vector<int> knapsack(int n, int w, const vector<int>& weights) {
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    
    // Xây dựng bảng dp
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (weights[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], weights[i - 1] + dp[i - 1][j - weights[i - 1]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    // Truy vết để lấy các món hàng được chọn
    int i = n, j = w;
    vector<int> selectedItems;
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            selectedItems.push_back(i - 1);
            j -= weights[i - 1];
        }
        i--;
    }
    
    return selectedItems;
}

int main() {
    int n, w;
    cin >> n >> w;
    
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    
    vector<int> selectedItems = knapsack(n, w, weights);
    
    cout << selectedItems.size() << endl;
  
    for (int i = selectedItems.size() - 1; i >= 0; i--) {
        cout << selectedItems[i] << " ";
    }
    cout << endl;
    
    return 0;
}
