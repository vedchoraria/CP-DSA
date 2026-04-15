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
// --- Logic ---
void solve() {
    ll n, x, y;
	cin >> n >> x >> y; 
	vector<ll> a(n, 0); 
	map<ll, vector<ll>> mp; 

	for(ll i = 0; i < n; i++) { 
			cin >> a[i];
			mp[a[i] % y].pb(a[i]); 
    }

	ll ans = 0;
		
	for(auto it : mp){
		vector<ll> v = it.second; 
		map<ll, ll> mp1; 
		for(ll i = 0; i<v.size();i++){
				mp1[v[i] % x]++;
		}
		for (auto it : mp1) { 
			if (it.first == 0 || (it.first == x / 2 && x % 2 == 0)) {
				ll cnt = it.second;
				ans += (cnt * (cnt - 1)) / 2; 
				it.second = 0;
			} else{
					ll cnt1 = it.second;
					ll cnt2 = mp1[x - it.first];
					ans += cnt1 * cnt2; 
					mp1[x - it.first] = 0; 
			}
			}
		}
		print(ans);
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