#include <bits/stdc++.h>
using namespace std;

// Function to solve 0/1 Knapsack Problem using Bottom-Up DP
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    // Create a DP table of size (n+1) x (W+1)
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the table dp[][] in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {

            // If weight of current item is more than current capacity,
            // it cannot be included — take value from previous row.
            if (wt[i - 1] > w)
                dp[i][w] = dp[i - 1][w];

            // Otherwise, decide to include or exclude the item
            else
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]],
                               dp[i - 1][w]);
        }
    }

    // The last cell contains the maximum profit
    return dp[n][W];
}

int main() {
    // Example input
    int n = 4;                    // Number of items
    vector<int> val = {60, 100, 120, 50};  // Profit values
    vector<int> wt  = {10, 20, 30, 5};     // Weights of items
    int W = 50;                   // Knapsack capacity

    // Function call
    cout << "Maximum Profit = " << knapsack(W, wt, val, n) << endl;
    return 0;
}



















