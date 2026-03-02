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
    long long n,k,x;
    cin>>n>>k>>x;
    
    vector<long long>a(n);
    for(auto &i:a) cin>>i;
    
    sort(a.begin(),a.end());
    
    vector<long long>gaps;
    long long groups=1;
    
    for(int i=1;i<n;i++){
        long long d=a[i]-a[i-1];
        if(d>x){
            groups++;
            gaps.push_back((d-1)/x);
        }
    }
    
    sort(gaps.begin(),gaps.end());
    
    for(long long g:gaps){
        if(k>=g){
            k-=g;
            groups--;
        }
        else break;
    }
    
    cout<<groups;
    
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