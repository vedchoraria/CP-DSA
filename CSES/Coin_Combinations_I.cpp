#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x;
    cin >> n >> x;

    vector<ll> coins(n);
    for (ll i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<ll> dp(x + 1, 0);
    dp[0] = 1;

    for (ll sum = 1; sum <= x; sum++) {
        for (ll coin : coins) {
            if (sum >= coin) {
                dp[sum] = (dp[sum] + dp[sum - coin]) % MOD;
            }
        }
    }

    cout << dp[x] << '\n';
}