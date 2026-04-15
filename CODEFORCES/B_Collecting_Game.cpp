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

// --- Constants ---
const int MOD = 1e9 + 7;
const ll INF = 1e18; // Changed to ll to match 1e18

// --- Logic ---
void solve() {
    ll n; 
	cin >> n;
	ll a;
	vector<pair<ll, ll>>v; 

	for (int i = 0; i < n; i++) {
		cin>>a;
		v.push_back({a, i});
	}
	vector<ll>pre(n); 
	sort(v.begin(), v.end());
	pre[0] = v[0].first;
	for(int i =1; i <n; i++) { 
		pre[i] = pre[i - 1] + v[i].first;
	}
	vector<ll> ans(n); 
	for (int i = 0; i< n; i++){
		int j = i;
		int found = i;
		while (j < n) {
			pair<ll, ll> temp = {pre[j] + 1, INT_MIN};
			ll idx = lower_bound(v.begin(), v.end(), temp) - v.begin();
			idx--;
			if (idx == j) {
				break;
			}
			found += idx - j;
			j = idx;
		}
		ans[v[i].second] = found;
	}

	for (int i = 0; i < n; i++) { 
		cout << ans[i] << " ";
	}
	cout << endl;

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