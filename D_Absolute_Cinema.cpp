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
    
    vector<ll> f(n+1 , 0); 
    for(ll i=1;i<=n;i++){
        cin>>f[i];
        // cout<<f[i]<<endl;
    }

    vector<ll>a(n+1, 0);
    for(ll i =2;i<n;i++){
        ll xyz = f[i+1] + f[i-1] -(2*f[i]);
        // cout<<"XYZ : "<<xyz<<endl;
        a[i] = xyz/2;
        // cout<<a[i]<<endl;
    }

    //Calculating an : 
    ll temp1 =0;
    for(ll i =2 ;i<n;i++){
        temp1 += a[i] * (i-1);
    }

    a[n] = (f[1] - temp1)/(n-1);

    //Calculating a1 : 
    temp1 =0;
    for(ll i =2 ;i<n;i++){
        temp1 += a[i] * (n-i);
    }

    a[1] = (f[n] - temp1)/(n-1);

    for(ll i =1;i<=n;i++)
    cout<<a[i]<<" ";

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