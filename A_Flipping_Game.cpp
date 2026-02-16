//Author : VED CHORARIA
#include <bits/stdc++.h>
using namespace std;

// --- Macros ---
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define cin(x) for(auto &i : (x)) cin >> i;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define print(x) cout << (x) << endl;
#define print_arr(x) for(int &i : (x)) cout << (x) << endl; cout<<endl;



// --- Constants ---
const int MOD = 1e9 + 7;
const ll INF = 1e18; // Changed to ll to match 1e18

// --- General Functions ---
bool isCo_Prime( int a , int b){
    return true ? gcd(a,b) == 1 : false;
}

long long power(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}
// --- Logic ---
void solve() {
    ll n;
    if (!(cin >> n)) return;
    
    vector<ll> b(n+1); 
    // cin(b);

    for(ll i=1;i<=n;i++) cin>>b[i];
    vector<vector<ll>>dp(n+2,vector<ll>(n+1,0));
    ll ans =0;
    for(ll j=n;j>=1;j--){
        for(ll i=n;i>=1;i--){
            dp[i][j] = dp[i+1][j] + (b[i] == 0 ? 1 : -1);
            cout<<"I : "<< i << " J  : "<< j << "  :- "<<dp[i][j]<<endl;
            ans = max(ans, dp[i][j]);
        }
    }

    print(ans);
    // Solve logic here
    
}

int main() {
    fastio;
    // int t = 1;
    // cin >> t; 
    // while (t--) {
        solve();
    // }
    // return 0;
}