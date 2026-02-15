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
bool f(int mid,int c,int m,int x){
 
    if(c<mid || m<mid){
        return false;
    }
    return ((c+m+x-3*mid)>=0);
};
 
// --- Solve function stub ---
void solve() {
 int c,m,x;
 cin>>c>>m>>x;
 int l=0,r=(c+m+1);
 
 while(r-l>1){
    int mid=(r+l)/2;
    if(f(mid,c,m,x))l=mid;
    else r=mid;
 }
 
 cout<<l<<endl;
 
 
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