// Author : VED CHORARIA

#include <bits/stdc++.h>
#include <bit>
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
long long mod(long long x)
{
    return ((x % MOD + MOD) % MOD);
}
long long add(long long a, long long b)
{
    return mod(mod(a) + mod(b));
}
long long mul(long long a, long long b)
{
    return mod(mod(a) * mod(b));
}

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
int helper(string s){
    int ans =0;
    for(char c : s) if(c=='1') ans++;
    return ans;
}
int helper2(string a , string b){
    int ans = 0;
    for(int i = 0; i<a.size() ;i++){
        if((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1') ) ans++;

    }
    return ans;
}
void solve() {
    ll n ; cin>>n;
    ll k;
    cin >> k;

    // vector<string> a(2*k+2);
    string x, y;
    cin>>x;
    cin>>y;
    ll m = (1LL << k) + 1;
    ll t1 = helper(x);
    ll t2 = helper(y);
    ll t3 = helper2(x,y);

    ll x1 = (t1)*(n-t1);
    ll x2 = (t2)*(n-t2);
    ll x3 = (t3)*(n-t3);
    ll ans = 0; ll i =0;
    // for(i =2 ; i<m; i+= 3){
    //     ans += x1 + x2 + x3;
    // }
    int temp = m/3;
    ans += 1LL * temp * (x1+x2+x3);

    if(m%3 == 1) ans += x1;
    if(m%3 == 2) ans += x1+x2;
    print(ans);


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