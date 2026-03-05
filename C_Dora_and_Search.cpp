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
    int n;
    if (!(cin >> n)) return;
    
    vector<int> v(n); 
    cin(v);
      if(n < 4){
    cout<<-1<<endl;return;
  }
  int st = 0, e = n-1, mn = 1, mx = n;
  bool got = false;
  while(st<e){
    while(v[st] == mn || v[st] == mx){
        if(v[st] == mn){st++; mn++;}
        else{st++; mx--;}
    }
    while(v[e] == mn || v[e] == mx){
        if(v[e] == mn) mn++;
        else mx--;
        e--;
    }
    if(st < e && v[st] != mn && v[st] != mx && v[e] != mn && v[e] != mx){
        got = true;break;
    }
  }
  if(got){
    cout<<st+1<<" "<<e+1<<endl;
  }else cout<<-1<<endl;
    
}

int main() {
    fastio;
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int t = 1;
    cin >> t; 
    while (t--) {
        solve();
    }
    return 0;
}