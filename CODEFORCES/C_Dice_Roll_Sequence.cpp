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
bool check(int f1, int f2){
    if(f1 == f2) return false;      
    if(f1+f2==7) return false;  
    return true;                   
}

void solve() {
    int n;
    cin>>n;
    vector<int>b(n);
    cin(b);
    vector<int> dp(7, 0);
    dp[b[0]] = 1;
    for(int i = 1; i < n; i++){
        vector<int>temp(7, 0);
        for(int v =1; v<=6; v++){
            int ma = 0;
            for(int u =1;u<=6;u++){
                if(check(u,v)){
                    ma = max(ma,dp[u]);
                }
            }
            temp[v] = ma;
            if(b[i] == v) temp[v] +=1;
            
        }
        dp = temp;
    }

    int max_kept = 0;
    for (int v = 1; v <= 6; ++v) {
        max_kept = max(max_kept, dp[v]);
    }

    // Min operations = Total elements - Max elements kept
    cout << n - max_kept << "\n";
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