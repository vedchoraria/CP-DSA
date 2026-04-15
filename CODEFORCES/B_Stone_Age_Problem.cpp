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
void a(vector<ll> &arr , ll &sum , vector<bool> &boccur, ll &extra){
    ll i ,x; cin>>i>>x; i--;
    if(boccur[i]){
        sum -= extra; sum += x;
        arr[i] = x;
        boccur[i] = false; print(sum);
        return;
    }
    sum -= arr[i];
    arr[i] = x; 
    sum += x;
    print(sum);
}
void b(vector<ll>& arr , ll &sum , vector<bool> &boccur, ll &extra){
    ll x; cin>>x;
    ll n = arr.size();

    boccur = vector<bool>(n,true);
    extra = x;
    sum = n*x;
    print(sum);
}
void solve() {
    ll n;
    if (!(cin >> n)) return;

    ll q; cin>>q;
    vector<bool> boccur(n,false); ll extra = 0;
    vector<ll>arr(n);
    cin(arr); ll sum =0;
    for(ll &i : arr) sum += i;
    while(q--){
        ll t; cin>>t;
       
        if(t== 1) a(arr , sum , boccur , extra);
        else b(arr , sum , boccur , extra);


        // for(bool i: boccur) cout<<i<<" ";
        // cout<<endl;
    }

    // Solve logic here
    
}

int main() {
    fastio;
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    // int t = 1;
    // cin >> t; 
    // while (t--) {
        solve();
    // }
    return 0;
}