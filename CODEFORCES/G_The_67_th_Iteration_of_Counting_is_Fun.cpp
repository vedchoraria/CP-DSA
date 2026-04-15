#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 676767677;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> b(n);
    for (int &x : b) cin >> x;

    vector<vector<int>> levels(m);
    for (int i = 0; i < n; i++) {
        levels[b[i]].push_back(i);
    }

    // Check validity
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) continue;

        bool ok = false;
        if (i > 0 && b[i-1] < b[i]) ok = true;
        if (i < n-1 && b[i+1] < b[i]) ok = true;

        if (!ok) {
            cout << 0 << "\n";
            return;
        }
    }

    ll ans = 1;
    ll cnt = 0;

    for (int t = 0; t < m; t++) {
        for (int i : levels[t]) {
            if (t == 0) continue;
            ans = (ans * cnt) % MOD;
        }
        cnt = levels[t].size();
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}