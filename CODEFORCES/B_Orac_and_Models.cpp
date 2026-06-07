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

ll help(vector<ll>&a, vector<vector<ll>>&dp, ll curr, ll prev ){
    // BASE CASE : 
    if(curr == a.size()) return 0;

    if(dp[curr][prev+1] != -1) return dp[curr][prev+1];

    ll take = 0;
    if(prev == -1 || (a[curr] > a[prev] && (curr+1) %(prev+1) == 0))
    take = 1 + help(a,dp,curr+1, curr);

    ll nt = help(a,dp,curr+1, prev);

    return dp[curr][prev+1] = max(take,nt);
}

// void solve() {

//     ll n;
//     cin >> n;

//     vector<ll> a(n);
//     input(a);
//     ll curr = 0, prev = -1;
//     vector<vector<ll>>dp (n+1, vector<ll>(n+1,-1));
//     ll ans = help(a,dp,curr,prev);
//     print(ans);
//     // for(auto it : dp){
//     //     debug(it);
//     // }

// }



void solve() {
    ll n; cin>>n;
    vector<ll> s(n); input(s);
 
 
    // State:
    // dp[i] = maximum number of models that Orac can buy s.t. the last 
    // model he bought was at index i
 
    // hence he can buy at index 2*i, 3*i, 4*i, ... <=n
    // dp[2*i] = max(dp[2*i], dp[i] + 1)
    // dp[3*i] = max(dp[3*i], dp[i] + 1)
 
    vector<ll> dp(n+1,1);
 
 
    // Base Case:
    // dp[i] = 1, for all i
    // we can start from anywhere and buy 1 model
 
    // Transition:
    for(ll i=1; i<=n; i++){
        for(ll j=2*i; j<=n; j+=i){
            if(s[j-1] > s[i-1]){
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }
 
    ll max_ans = INT_MIN;
    for(ll i=1; i<=n; i++){
        max_ans = max(max_ans, dp[i]);
    }
    print(max_ans);
}
 


// -------------------- MAIN --------------------

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