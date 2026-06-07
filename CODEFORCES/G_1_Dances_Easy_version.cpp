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

void solve() {

    ll n;
    cin >> n;
    ll m; cin>>m;

    vector<ll> a(n), b(n);
    a[0] = 1;
    for(ll i = 1; i< n;i++){
        cin>>a[i];
    }
     input(b);
     sort(a.begin(), a.end());
     sort(b.begin() , b.end());

    ll ops = 0;
    ll i =0 , j =0;
    //selling c[0] = 1;

    while(j<n && b[j] <= 1){
        // debug(j);
        j++; ops++;
        
    }
    j++;
    i++;

    while(i<n && j < n){
        if(b[j] <= a[i]){
            // debug(j);
            j++; ops++;
            
        }
        else {
            i++; j++;
        }
    }

    print(ops);

    // debug(a); debug(b);

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