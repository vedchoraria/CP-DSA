//Author : VED CHORARIA
#include <bits/stdc++.h>
using namespace std;

// --- Macros ---
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define cin(x) for(int &i : (x)) cin >> i;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define print(x) cout << (x) << endl;

// --- Constants ---
const int MOD = 1e9 + 7;
const ll INF = 1e18; // Changed to ll to match 1e18

// --- Logic ---
void solve() {
    int n;
    if (!(cin >> n)) return;
    int m;
    cin>>m;
    vector<vector<int>>b(m,vector<int>(n));
    for(auto it : b) cin(it);
    ll ans = 0;
    for(int j = 0; j<m; j++) {
        sort(b[j].begin(), b[j].end());
        for(int i = 0; i<n;i++) {
            // How many elements are smaller than this (indices 0 to i-1)? -> i
            // How many elements are larger than this (indices i+1 to n-1)? -> (n - 1 - i)
            // Coefficient = count_smaller - count_larger
            ll coeff = i - (n - 1 - i);
            
            ans += (ll)b[j][i] * coeff;
        }
    }
    print(ans);
    
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