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
    
    vector<ll> b(n); 
    for(ll& i: b)
    cin>>i;

    // Solve logic here
    
    ll cnt =0;
    ll nega =0;
    ll mi = 10e10;
    for(ll i : b){
        if(i<=0){
            nega++;
            
        }
        mi= min(mi, abs(i));
        cnt+= abs(i);
    }
    // cout<<"TOTAL :"<<cnt<<endl;
    // cout<<"nega :"<<nega<<endl;
    if(nega&1){
        cnt -= 2*mi;
    }

    print(cnt);
    
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