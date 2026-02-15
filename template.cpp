#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<map>
#define ll long long 
#define mp make_pair
using namespace std;
const ll MOD = 1e9+7;
bool isPrime(ll n){#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define all(v) (v).begin(), (v).end()
 
typedef vector<int> vll;
 
const int MOD = 1000000007;
 
// --- Debugging helpers ---
template<typename T>
void __print(const T &x) { cerr << x; }
 
template<typename T, typename U>
void __print(const pair<T, U> &p) {
    cerr << '('; __print(p.first); cerr << ", "; __print(p.second); cerr << ')';
}
 
template<typename T>
void __print(const vector<T> &v) {
    cerr << '[';
    for (size_t i = 0; i < v.size(); i++) {
        __print(v[i]);
        if (i + 1 < v.size()) cerr << ", ";
    }
    cerr << ']';
}
 
template<typename T>
void __print(const set<T> &s) {
    cerr << '{';
    bool first = true;
    for (const auto &x : s) {
        if (!first) cerr << ", ";
        __print(x);
        first = false;
    }
    cerr << '}';
}
 
template<typename T, typename U>
void __print(const map<T, U> &m) {
    cerr << '{';
    bool first = true;
    for (const auto &p : m) {
        if (!first) cerr << ", ";
        __print(p);
        first = false;
    }
    cerr << '}';
}
 
template<typename... Args>
void dbg_out() {
    cerr << "\n";
}
 
template<typename T, typename... Args>
void dbg_out(T t, Args... args) {
    __print(t);
    if (sizeof...(args)) cerr << " | ";
    dbg_out(args...);
}
 
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "] = ", dbg_out(__VA_ARGS__)
 
// --- Input/output Helpers ---
void ioar(int arr[], int size) {
    for (int i = 0; i < size; i++) cin >> arr[i];
}
 
void ioar(vector<int> &v, int size) {
    v.resize(size);
    for (int &x : v) cin >> x;
}
 
void opar(const int arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << ' ';
    cout << '\n';
}
 
void opar(const vector<int> &v) {
    for (const int &x : v) cout << x << ' ';
    cout << '\n';
}
 
// --- Utility functions ---
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
 
int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}
 
vll sieve(int n) {
    vll primes(n + 1, 1);
    primes[0] = primes[1] = 0;
    for (int i = 2; i * i <= n; i++)
        if (primes[i])
            for (int j = i * i; j <= n; j += i)
                primes[j] = 0;
    return primes;
}
 
int fast_pow(int base, int exp, int mod = MOD) {
    int res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
 
// --- Solve function stub ---
void solve() {

}
 
// --- Main ---
signed main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
    for(ll i = 2; i*i <=n; i++){
        if(n%i == 0) return false;
    }
    return true;
}
void solve(){
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    if(!(cin >> t)) return 0;

    while(t--){
        solve();
    }
}
