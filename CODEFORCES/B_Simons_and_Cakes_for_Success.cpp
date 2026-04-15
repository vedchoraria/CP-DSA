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
void printPrimeFactors(long long n  , set<int> &s) {
    // Print the number of 2s that divide n
    while (n % 2 == 0) {
        s.insert(2);
        n = n / 2;
    }

    // n must be odd at this point. So we can skip one element (i=3) and 
    // increment i by 2 (i=5, 7, 9, ...)
    for (long long i = 3; i * i <= n; i = i + 2) {
        // While i divides n, print i and divide n
        while (n % i == 0) {
            s.insert(i);
            n = n / i;
        }
    }

    // If n is a prime number greater than 2, it will not become 1 by the above loops
    if (n > 2) {
        s.insert(n);
    }
}

//LCM FUnc
// --- Logic ---
void solve() {
    ll n;
    if (!(cin >> n)) return;
    ll ans = 1;
    set<int>s;
    printPrimeFactors(n, s);
    for(auto it : s){
        ans = ans*it;
    }
    print(ans);

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