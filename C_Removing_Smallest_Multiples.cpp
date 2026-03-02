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
#define print_arr(x) for(int &i : (x)) cout << i << endl; cout<<endl;



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
//LCM FUnc
// --- Logic ---
void solve() {
    ll n;
    if (!(cin >> n)) return;
    string s;
    cin>>s;
    ll ans=0;
    vector<bool>vis(n,false);
    for(ll i=0;i<n;i++){
        if(s[i] == '0'){
            ll pos = i+1;
            ll fact =1;
            while(pos<=n){
                if(s[pos-1] == '0' && vis[pos-1] == false)
                {ans += (i+1); vis[pos-1] = true;}
                else if(s[pos-1] == '1') break;

                fact++;
                pos = (i+1)* fact;

            }
        }
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