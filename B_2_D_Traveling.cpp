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
ll get(vector<ll>& x , vector<ll>& y , ll a , ll b){
    return abs(x[a-1] - x[b-1]) + abs(y[a-1] - y[b-1]);
}
// --- Logic ---
void solve() {
    ll n;
    if (!(cin >> n)) return;
    ll k , a , b;
    cin >> k >> a >> b;
    vector<ll> x(n) , y(n); 
    for( ll i =0 ; i< n; i++){
        cin>>x[i] >> y[i];
    }
    ll mins = 1e17, mine = 1e17;

    for(ll i =1 ; i<=k;i++){
        mins = min(mins , get(x , y , a , i));

        mine = min(mine , get(x , y , b , i));
    }

    print( min(get(x,y,a,b) , mins + mine));




    // Solve logic here
    
}

int main() {
    fastio;
    int t = 1;
    cin >> t; 
    while (t--) {
        solve();
    }
    return 0;
}