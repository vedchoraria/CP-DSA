#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

long long MOD = 998244353;

// Helper to precompute factorials
vector<long long> fact;
void precompute_factorials(int n) {
    fact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % MOD;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    long long total_sum = 0;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
        total_sum += a[i];
    }

    long long q = total_sum / n;
    int r = total_sum % n;
    long long a0 = a[0];

    // dp[j][k] = number of ways to pick j people for the "r" group
    // with total shared box debt k. 
    // We cap k at a0 since anything more is useless.
    vector<vector<long long>> dp(r + 1, vector<long long>(a0 + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        long long x = max(0LL, (q + 1) - a[i]); // Cost if in first r group
        long long y = max(0LL, q - a[i]);       // Cost if in remaining group
        
        vector<vector<long long>> next_dp(r + 1, vector<long long>(a0 + 1, 0));

        for (int j = 0; j <= r; j++) {
            for (int k = 0; k <= a0; k++) {
                if (dp[j][k] == 0) continue;

                // Option 1: Put person i in the group that takes q decorations
                if (k + y <= a0) {
                    next_dp[j][k + y] = (next_dp[j][k + y] + dp[j][k]) % MOD;
                }

                // Option 2: Put person i in the group that takes q+1 decorations (if space in r)
                if (j + 1 <= r && k + x <= a0) {
                    next_dp[j + 1][k + x] = (next_dp[j + 1][k + x] + dp[j][k]) % MOD;
                }
            }
        }
        dp = move(next_dp);
    }

    long long ways_to_choose_groups = 0;
    for (int k = 0; k <= a0; k++) {
        ways_to_choose_groups = (ways_to_choose_groups + dp[r][k]) % MOD;
    }

    // Result = (ways to partition) * (permutations of r) * (permutations of n-r)
    long long ans = (ways_to_choose_groups * fact[r]) % MOD;
    ans = (ans * fact[n - r]) % MOD;

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute_factorials(55);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}