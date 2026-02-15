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
    cin>>n;
    string s;
    cin>>s;
    unordered_map<char, int>mpp;
    int ans = 0;
    for(int i=0; i<n; i++){
        mpp[s[i]]++;
        ans += mpp.size(); 
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