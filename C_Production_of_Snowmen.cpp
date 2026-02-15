//Author : VED CHORARIA
#include <bits/stdc++.h>
using namespace std;

// --- Macros ---
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// --- Constants ---
const int MOD = 1e9 + 7;
const ll INF = 1e18; // Changed to ll to match 1e18

// --- Logic ---

ll count_valid_shifts(int n, vector<int>& a, vector<int>& b) {
    ll ans = 0;
    for(int s = 0; s < n; ++s){
        bool val = true;
        for(int m = 0; m < n; ++m){
            if(a[m] >=b[(m + s)%n]){
                val = false;
                break;
            }
        }
        if(val){
            ans++;
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) cin >> c[i];
    ll temp1 = count_valid_shifts(n,a,b);
    ll temp2 = count_valid_shifts(n,b,c);
    cout<<n*temp1*temp2<<endl;
}

int main() {
    fastio;
    int t = 1;
    cin >> t; 
    while (t--) {
        solve();
    }
    return 0;
}