#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> dp(n + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int d = 1; d <= 6; d++) {
            if (i - d >= 0) {
                dp[i] = (dp[i] + dp[i - d]) % MOD;
            }
        }
    }

    cout << dp[n] << '\n';
}