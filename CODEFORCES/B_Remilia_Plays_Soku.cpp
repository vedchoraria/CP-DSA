#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void solve() {
    ll n, x1, x2, k;
    cin >> n >> x1 >> x2 >> k;
    ll temp = abs(x1 - x2);
    ll d = min(temp, n - temp);
    if (n <= 3) {
        cout<<d<<endl;
    }
    else {
        cout << d + k << "\n";
    }
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}