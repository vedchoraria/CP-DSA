// Author : VED CHORARIA

#include <bits/stdc++.h>
using namespace std;

// -------------------- TYPEDEFS --------------------

using ll = long long;

// -------------------- MACROS --------------------

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

#define pb push_back
#define all(x) (x).begin(), (x).end()

#define endl '\n'

#define YES cout << "YES\n"
#define NO cout << "NO\n"

// -------------------- DEBUG --------------------

#ifndef ONLINE_JUDGE

#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;

void _print(int x) { cerr << x; }
void _print(ll x) { cerr << x; }
void _print(string x) { cerr << x; }

template<class T>
void _print(vector<T> v) {
    cerr << "[ ";
    for (auto i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

#else
#define debug(x)
#endif

// -------------------- CONSTANTS --------------------

const int MOD = 1e9 + 7;
const ll INF = 1e18;

// -------------------- HELPER FUNCTIONS --------------------

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

ll power(ll base, ll exp) {

    ll res = 1;

    while (exp > 0) {

        if (exp & 1)
            res = (res * base) % MOD;

        base = (base * base) % MOD;

        exp >>= 1;
    }

    return res;
}

bool isCoPrime(int a, int b) {
    return (__gcd(a, b) == 1);
}

// -------------------- SOLVE --------------------

void solve() {

    ll n;
    cin >> n;

    vector<ll> a(n), b(n);

    input(a);
    input(b);

    ll max_diff = -INF;

    // Compute ai - bi

    for (ll i = 0; i < n; i++) {

        a[i] = a[i] - b[i];

        max_diff = max(max_diff, a[i]);
    }

    debug(a);
    debug(max_diff);

    vector<int> strong;

    for (ll i = 0; i < n; i++) {

        if (a[i] == max_diff) {
            strong.pb(i + 1);
        }
    }

    cout << strong.size() << endl;

    printVec(strong);
}

// -------------------- MAIN --------------------

int main() {

    fastio;

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}