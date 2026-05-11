//Author : VED CHORARIA
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define cin(x) for(auto &i : (x)) cin >> i;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define print(x) cout << (x) << endl;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    ll n;
    if (!(cin >> n)) return;

    vector<ll> b(n);
    cin(b);

    // Suffix minimum (including b[i] itself)
    vector<ll> suff(n, 0);
    suff[n - 1] = b[n - 1];

    ll ans = 0;
    for (ll i = n - 2; i >= 0; i--) {
        suff[i] = min(suff[i + 1], b[i]);
        ans += max((ll)0, b[i] - suff[i]);
    }

    // Previous strictly smaller element (monotonic stack)
    vector<ll> prev(n, 0);
    stack<ll> st;
    for (ll k = 0; k < n; k++) {
        while (!st.empty() && b[st.top()] >= b[k]) st.pop();
        prev[k] = st.empty() ? -1 : st.top(); // ✅ -1 means no previous smaller
        st.push(k);
    }

    // Find best gain from one optional decrease
    ll best = 0;
    for (ll k = 0; k < n; k++) {
        if (b[k] == suff[k]) {             // b[k] is suffix min from k onward
            ll gain = (k - 1) - prev[k];   // columns prev[k]+1 ... k-1 all gain
            best = max(best, gain);
        }
    }

    print(ans + best);
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}