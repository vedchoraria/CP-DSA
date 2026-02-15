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
    int k;
    cin>>k;
    vector<int> a(n) , b(n);
    cin(a); cin(b);
    //Storing what's maximum , at each posn of b
    vector<int>bmax(n);
    bmax[0] = b[0];
    for(int i = 1; i < n; i++) bmax[i] = max(bmax[i-1], b[i]);
    int ans = a[0] + (k-1) * bmax[0];
    int temp = a[0];
    for(int i=1 ; i<n;i++){
        if(k-(i+1) <0) break;
        temp += a[i];
    ans = max(ans , temp + ((k-1-i) * bmax[i]));
    }
    print(ans);
    // Solve logic here
    
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