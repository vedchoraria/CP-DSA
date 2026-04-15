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

    // cout<<"ENTER"<<endl;
    ll n,m;
    if (!(cin >> n)) return;
    cin>>m;
    // cout<<"ENTERrrrrrrrrrrr"<<endl;
    vector<ll> b(m+1); 
    
    
    b[0] = 1; 
    // n-i+1 and 
    // if val  < pre  = n-pre + val
    //else val > pre = val-pre
    for(ll i = 1;i<=m;i++) cin>>b[i];

    // Solve logic here

    ll time =0;
    ll pre = 1;
  
    for(ll i =1 ;i<=m;i++){
        if(b[i] < pre){
            time += n-pre+b[i];
        }
        else if(b[i] > pre){
            time += b[i]-pre;
        }
        else continue;

        pre = b[i];
    }

    print(time);
    
}

int main() {
    fastio;
    // int t = 1;
    // cin >> t; 
    // while (t--) {
        solve();
    // }
    return 0;
}