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
  int n; cin>>n;
  int x;cin>>x;
  vector<int>v; v.push_back(x);
  for(int i=1; i<n; i++){
    cin>>x;
    if(v.back() != x) v.pb(x);
  }
  int sz = v.size();
  if(sz == 1){
    cout<<1<<endl;
    return;
  }
  int c = 2;
  for(int i=1; i<sz -1; i++){
    if( (v[i-1] < v[i] && v[i] > v[i+1] ) ||
        (v[i-1] > v[i] && v[i] < v[i+1] )) c++;
  }
  cout<<c<<endl;

    
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