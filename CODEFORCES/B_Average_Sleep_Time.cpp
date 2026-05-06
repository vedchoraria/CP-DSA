// Author : VED CHORARIA
#include <bits/stdc++.h>
using namespace std;

// --- Macros ---
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// --- Constants ---
const int MOD = 1e9 + 7;

// --- Logic ---
void solve() {
    int n, k;
    cin >> n >> k;

    vector<long long> pref(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        pref[i] = pref[i - 1] + x;
    }

    long long total = 0;

    // all subarrays of length k
    for (int i = 1; i <= n - k + 1; i++) {

        long long subarraySum =
            pref[i + k - 1] - pref[i - 1];

        total += subarraySum;
    }

    int cnt = n - k + 1;

    double ans = (double)total / cnt;

    cout << fixed << setprecision(10)
         << ans << endl;
}
int main() {
    fastio;

    // int t = 1;
    // cin >> t;

    // while (t--) {
        solve();
    // }

    return 0;
}