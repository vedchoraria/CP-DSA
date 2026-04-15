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
    int m; cin>>m;
    vector<int> b(m); 
    cin(b); int ans = m;
    sort(all(b));

    vector<ll> gaps;

    for(int i = 0; i < m-1; i++)
    gaps.push_back(b[i+1] - b[i] - 1);

    // circular gap
    gaps.push_back(n - b[m-1] + b[0] - 1);

    sort(gaps.rbegin(), gaps.rend());

    ll days = 0;
    ll saved = 0;

    for(auto gap : gaps) {
        ll remaining = gap - 2*days;

        if(remaining <= 0) continue;

        if(remaining == 1) {
            saved += 1;
            days += 1;
        }
        else {
            saved += remaining - 1;
            days += 2;
        }
    }
    print(n-saved);

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