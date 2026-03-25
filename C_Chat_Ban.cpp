//Author : VED CHORARIA
#include <bits/stdc++.h>
using namespace std;

// --- Macros ---
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define print(x) cout << (x) << endl;
#define print_arr(x) for(int &i : (x)) cout << i << endl; cout<<endl;
// --- Constants ---
const ll INF = 1e18;

// --- Helper: sum till day d ---
ll get(ll k, ll d) {
    if (d <= k) {
        return d * (d + 1) / 2;
    } else {
        ll first = k * (k + 1) / 2;
        ll rem = d - k;
        ll second = rem * (2 * k - rem - 1) / 2;
        return first + second;
    }
}

// --- Solve ---
void solve() {
    ll k, x;
    cin >> k >> x;

    ll l = 1, r = 2 * k - 1;
    ll ans = r;

    while (l <= r) {
        ll mid = (l + r) / 2;

        if (get(k, mid) >= x) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

   print(ans);
}

int main() {
    fastio;
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}