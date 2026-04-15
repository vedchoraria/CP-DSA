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
void check(vector<ll>h , ll len){
    ll n = h.size() , ans = 0;
    for(ll i =0;i<n;i++){
        if(h[i] > len) break;
        ans+= h[i];
    }

    cout<<ans<<" ";
}
void solve() {
    ll n;
    if (!(cin >> n)) return;
    ll k;
    cin>>k;
    vector<ll>h(n), temp(k);
    cin(h); 
    cin(temp);
    vector<ll>prefmax(n),prefsum(n);
    prefmax[0] = h[0], prefsum[0] = h[0];

    for(ll i= 1;i<n;i++){
        prefmax[i] = max(prefmax[i-1], h[i]);
        prefsum[i] += prefsum[i-1]+ h[i];

    }
    for(ll i=0;i<k;i++){
        int pos = upper_bound(prefmax.begin(), prefmax.end(), temp[i])-prefmax.begin()-1;
        if(pos<0) cout<<0 << " ";
        else cout<<prefsum[pos]<<" ";
    }

    cout<<endl;

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