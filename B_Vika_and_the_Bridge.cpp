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
    int n, k;
    cin >> n >> k;

    vector<int> c(n);
    for(auto &x : c) cin >> x;

    vector<vector<int>> pos(k+1);

    for(int i=0;i<n;i++)
        pos[c[i]].push_back(i+1);

    int ans = INT_MAX;

    for(int color=1;color<=k;color++){

        vector<int> p;
        p.push_back(0);

        for(int x:pos[color])
            p.push_back(x);

        p.push_back(n+1);
        if(p.size() <=3) continue;

        int largest = 0;
        int second = 0;

        for(int i=1;i<p.size();i++){
            int gap = p[i]-p[i-1]-1;

            if(gap > largest){
                second = largest;
                largest = gap;
            }
            else if(gap > second){
                second = gap;
            }
        }

        int cur = max(second, (largest+1)/2);
        // cout<<color<<" : "<<cur<<endl;
        ans = min(ans, cur);
    }

    cout << ans << "\n";
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