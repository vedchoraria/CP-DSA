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
    
    vector<ll> b(n); 
    cin(b);
    ll ops =0;
    vector<vector<ll>>xyz;
    ll j = n-2;
    ll mi = b[j] , ma = b[j+1];
    ll miIn = j , maIn = j+1;
    if(mi>ma){
        print(-1); return;
    }
    for(j;j >=0 ;j--){
        
        if(b[j] > b[j+1]) {
            b[j] = mi - ma;
            if(b[j] >= 10e18) b[j] = 10e18-1;
            ops++;
            // cout<<j+1 << " " << miIn +1<<" " << maIn +1<<endl;
            xyz.pb( {j+1 , miIn +1 , maIn +1} );
        }

        if(b[j] > b[j+1]){
            print(-1); return;
        }

        if(b[j] < mi){
            mi = b[j];
            miIn = j;
        }
        if(b[j] > ma){
            ma = b[j];
            maIn = j;
        }



    }

    print(ops);
    for(auto it : xyz){
        for(ll i : it){
            cout<<i<<" ";
        }

        cout<<endl;
    }

    // Solve logic here
    
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