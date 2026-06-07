// Author : VED CHORARIA

#include <bits/stdc++.h>
using namespace std;

// -------------------- TYPEDEFS --------------------

using ll = long long;
using ld = long double;

using pii = pair<int,int>;
using pll = pair<ll,ll>;

template<typename T>
using vec = vector<T>;

// -------------------- MACROS --------------------

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()

#define endl '\n'

#define YES cout << "YES\n"
#define NO cout << "NO\n"

#define print(x) cout << (x) << endl

// -------------------- DEBUG --------------------

#ifndef ONLINE_JUDGE

#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;

void _print(int x) { cerr << x; }
void _print(ll x) { cerr << x; }
void _print(string x) { cerr << x; }
void _print(char x) { cerr << x; }
void _print(bool x) { cerr << x; }

template<class T>
void _print(vector<T> v) {
    cerr << "[ ";
    for (auto i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template<class T, class V>
void _print(pair<T,V> p) {
    cerr << "{ ";
    _print(p.first);
    cerr << ", ";
    _print(p.second);
    cerr << " }";
}

#else
#define debug(x)
#endif

// -------------------- CONSTANTS --------------------

const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

// -------------------- DIRECTIONS --------------------

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// -------------------- MATH UTILS --------------------

ll power(ll a, ll b, ll mod = MOD) {
    ll res = 1;

    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;

        a = (a * a) % mod;
        b >>= 1;
    }

    return res;
}

ll gcdll(ll a, ll b) {
    return __gcd(a, b);
}

ll lcmll(ll a, ll b) {
    return (a / gcdll(a, b)) * b;
}

bool isPrime(ll n) {
    if (n < 2) return false;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

ll factorial(int n) {
    ll res = 1;

    for (int i = 2; i <= n; i++)
        res *= i;

    return res;
}

// -------------------- HELPERS --------------------

template<class T>
void input(vector<T>& v) {
    for (auto &x : v)
        cin >> x;
}

template<class T>
void printVec(vector<T>& v) {
    for (auto &x : v)
        cout << x << " ";

    cout << endl;
}

template<class T>
bool chmax(T &a, T b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmin(T &a, T b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

// -------------------- SOLVE --------------------

vector<vector<vector<ll>>> dp;
ll n; string s , w;

ll solve(ll i , bool one, bool two){
    //BASE CASE
    if(i == n){
        if(one && two) return 1;
        return 0;
    }
    //avoid calculating similar states
    if(dp[i][one][two] != -1) return dp[i][one][two];

    // FIRST CASE : only numbers
    if(s[i] != '?' && w[i] != '?'){
        if(s[i] > w[i]){
            dp[i][one][two] = solve(i+1, true, two) % MOD;
        }
        else if(s[i] < w[i]){
            dp[i][one][two] = solve(i+1, one, true) % MOD;
        }
        else {
            dp[i][one][two] = solve(i+1, one , two) % MOD;
        }
        dp[i][one][two] %= MOD;
    }
    else{
        dp[i][one][two] = 0;
        if(s[i] == '?' && w[i] == '?'){
            // c1 : assuming putting both numbers same 10 pairs for that 
            dp[i][one][two] += 10*(solve(i+1, one , two)% MOD) % MOD;
            dp[i][one][two] %= MOD;
            // assuming you satisfy condn 1 : 45 pairs for that
            dp[i][one][two] += 45*(solve(i+1, true, two)% MOD)% MOD;
            dp[i][one][two] %= MOD;
            //assuming you satify cond 2 , : 45 pairs for that 
            dp[i][one][two] += 45*(solve(i+1, one, true)% MOD)% MOD;
            dp[i][one][two] %= MOD;
        }
        else if(s[i] == '?'){
            // option to put numbers only in one place
            ll cnt = w[i]-'0';
            // for 1st condn : 9-cnt , 2nd condn cnt 
            dp[i][one][two] += (solve(i+1, one , two)% MOD) % MOD; // do nothing
            dp[i][one][two] %= MOD;
            dp[i][one][two] += (9-cnt)*(solve(i+1, true, two) % MOD) % MOD;
            dp[i][one][two] %= MOD; 
            dp[i][one][two] += (cnt)*(solve(i+1, one, true)% MOD)% MOD;
            dp[i][one][two] %= MOD;
        }
        else {
            // option to put numbers only in one place
            ll cnt = s[i]-'0';
            // for 1st condn : 9-cnt , 2nd condn cnt 
            dp[i][one][two] += solve(i+1, one, two)% MOD; // do nothing
            dp[i][one][two] %= MOD;
            dp[i][one][two] += (cnt)*(solve(i+1, true, two)% MOD)% MOD;
            dp[i][one][two] %= MOD;
            dp[i][one][two] += (9-cnt)*(solve(i+1, one, true)% MOD)% MOD;
            dp[i][one][two] %= MOD;
        }
    }

    return dp[i][one][two]%MOD;

}
void t() {

    
    cin >> n;

    
    cin>>s>>w;
    // STATES : index , first condn true , 2nd condn true
    dp.assign(n+1, vector<vector<ll>>(2, vector<ll>(2,-1)));
    ll ans = solve(0, false, false);
    print(ans);
    // debug(dp);

}

// -------------------- MAIN --------------------

int main() {

    fastio;

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    // int t = 1;
    // cin >> t;

    // while (t--) {
        t();
    // }

    return 0;
}