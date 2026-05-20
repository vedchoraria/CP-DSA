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
const ll INF = 1e18;

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
        return 0;
    }
    int position = 0;
    while (n != 0) {
        n >>= 1;
        position++;
    }
    return position;
}

void printPrimeFactors(long long n) {
    while (n % 2 == 0) {
        std::cout << 2 << " ";
        n = n / 2;
    }

    for (long long i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            std::cout << i << " ";
            n = n / i;
        }
    }

    if (n > 2) {
        std::cout << n << " ";
    }
}

long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

map<pair<int,int>,int> dp;

int calc(int pos , int need , int n ,vector<vector<int>>&good ,vector<vector<int>>&bad ){
    if(need > n) return n;
    pair<int,int> state = {pos , need};
    if(dp.count(state))
        return dp[state];
    int g = 1e9 , bd = 1e9;
    auto it1 = lower_bound(all(good[need]) , pos);
    if(it1 != good[need].end())
        g = *it1;
    auto it2 = lower_bound(all(bad[need]) , pos);
    if(it2 != bad[need].end())
        bd = *it2;
    if(bd < g)
        return dp[state] = bd - 1;
    if(g == (int)1e9)
        return dp[state] = n;
    return dp[state] = calc(g + 1 , need + 1 , n , good , bad);
}

void solve() {

    int n;
    cin >> n;
    vector<int>a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    vector<vector<int>> good(n+2),bad(n+2);
    for(int i=1;i<=n;i++){
        if(a[i] == b[i]){
            good[a[i]].pb(i);
        }
        else{
            bad[a[i]].pb(i);
            bad[b[i]].pb(i);
        }
    }
    dp.clear();
    ll ans = 0;
    for(int l=1;l<=n;l++){
        int r = calc(l , 1 , n , good , bad);
        if(r >= l)
            ans += (r - l + 1);
    }
    print(ans);
}

int main() {

    fastio;

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}