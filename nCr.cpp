#include <bits/stdc++.h>
using namespace std;

int binomialCoeff(int n, int k) {
    vector<vector<int>> C(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][k];
}

int main() {
    int n = 5, k = 2;
    cout << "Binomial Coefficient C(" << n << "," << k << ") = " << binomialCoeff(n, k);
}
