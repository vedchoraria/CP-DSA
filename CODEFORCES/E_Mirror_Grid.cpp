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
    int n;
    if (!(cin >> n)) return;
    
    vector<string>v(n);
    
    for(int i =0;i<n;i++){
        cin>>v[i];

    }
    int cnt =0;
    
    for(int i=0;i<n/2;i++){
        for(int j=0;j<(n+1)/2;j++){
            int ones=0,zero=0;
            if(v[i][j]=='0')zero++;
            else ones++;
            if(v[j][n-1-i]=='0')zero++;
            else ones++;
            if(v[n-1-i][n-1-j]=='0')zero++;
            else ones++;
            if(v[n-j-1][i]=='0')zero++;
            else ones++;
            cnt+=min(ones,zero);
        }
    }

    print(cnt);

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