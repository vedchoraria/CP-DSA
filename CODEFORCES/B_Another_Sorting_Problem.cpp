//Author : VED CHORARIA
#include <bits/stdc++.h>
using namespace std;

// --- Macros ---
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define cin(x) for(auto &i : (x)) cin >> i;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define print(x) cout << (x) << endl;
#define print_arr(x) for(int &i : (x)) cout << i << " "; cout<<endl;
#define pys cout<<"YES\n"
#define pno cout<<"NO\n"


// --- Constants ---
const int MOD = 1e9 + 7;
const ll INF = 1e18; // Changed to ll to match 1e18

// --- General Functions ---
bool isCo_Prime( int a , int b){
    return true ? gcd(a,b) == 1 : false;
}

ll power(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

int findMaxBitPosition(int n) {
    if (n == 0) {
        return 0; // No set bits
    }
    int position = 0;
    while (n != 0) {
        n >>= 1;      // Right shift n by 1
        position++;   // Increment position counter
    }
    return position;
}
void printPrimeFactors(ll n) {
    // Print the number of 2s that divide n
    while (n % 2 == 0) {
        std::cout << 2 << " ";
        n = n / 2;
    }

    // n must be odd at this point. So we can skip one element (i=3) and 
    // increment i by 2 (i=5, 7, 9, ...)
    for (ll i = 3; i * i <= n; i = i + 2) {
        // While i divides n, print i and divide n
        while (n % i == 0) {
            std::cout << i << " ";
            n = n / i;
        }
    }

    // If n is a prime number greater than 2, it will not become 1 by the above loops
    if (n > 2) {
        std::cout << n << " ";
    }
}

ll factorial(int n) {
    ll res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}





struct Range {
    ll l, r;
    bool ok;
};

Range mergeRange(Range a, ll nl, ll nr) {
    if (!a.ok) return {0, 0, false};

    ll L = max(a.l, nl);
    ll R = min(a.r, nr);
    if(L > R) return {0, 0, false};

    return {L, R, true};
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    cin(a);
    vector<ll>b = a;
    sort(b.begin(), b.end());
    if(b == a){
        pys;
        return;
    }

    Range dp[2];
    dp[0] = {1, INF, true};
    dp[1] = {1, INF, true};

    for(int i =0;i<n-1;i++){
        Range ndp[2] = {
            {0, 0, false},
            {0, 0, false}
        };
        for(int p=0; p<=1; p++){
            if (!dp[p].ok) continue;
            for(int c =0; c<=1; c++) {
                ll low = 1;
                ll high = INF;
                if(p == c){
                    if(a[i] > a[i + 1]) continue;
                }
                else if(p == 0 && c == 1){
                    low = max(low, a[i]-a[i + 1]);
                }
                else{
                    high = min(high, a[i + 1]-a[i]);
                }
                if(high < low) continue;
                Range mer = mergeRange(dp[p], low, high);
                if(!mer.ok) continue;
                if(!ndp[c].ok){
                    ndp[c] = mer;
                }else{
                    ndp[c].l = min(ndp[c].l, mer.l);
                    ndp[c].r = max(ndp[c].r, mer.r);
                }
            }
        }
        dp[0] = ndp[0];
        dp[1] = ndp[1];
    }
    if(dp[0].ok || dp[1].ok) pys;
    else pno;
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