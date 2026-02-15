//Author : VED CHORARIA
#include <bits/stdc++.h>
using namespace std;

// --- Macros ---
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define cin(x) for(int &i : (x)) cin >> i;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define print(x) cout << (x) << endl;
#define print_arr(x) for(int &i : (x)) cout << (x) << endl; cout<<endl;



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
bool check(ll &mid, ll &S, vector<ll> &arr , ll &tot){
    vector<ll>prices(arr.size());
    for(ll i=0;i<arr.size();i++){
        prices[i] = arr[i] + (i+1)*mid;
    }
    sort(prices.begin() , prices.end());

    ll cost = 0;
    for(ll i =0;i<mid;i++){
        cost+= prices[i];
        if(cost>S) return false;
    }
    tot = cost;
    return true;
}
// --- Logic ---
void solve() {
    ll n;
    if (!(cin >> n)) return;
    ll S;
    cin>>S;

    vector<ll> a(n); 
    for(ll &i:a) cin>>i;
    

    ll l =0, h=n;
    ll T=0;
    ll k =0;
    while(l<=h){
        ll mid = l+(h-l)/2;
        ll temp =0;
        if(check(mid, S, a ,temp)){
            k = mid; T=temp;
            l=mid+1;
        }else {h = mid-1;}
    }
    // Solve logic here
    cout<<k <<" "<<T<<endl;
}

int main() {
    fastio;
    // int t = 1;
    // cin >> t; 
    // while (t--) {
        solve();
    // }
    return 0;
}