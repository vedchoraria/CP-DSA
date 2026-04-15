//Author : VED CHORARIA
#include <bits/stdc++.h>
using namespace std;

// --- Macros ---
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
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
void solve(){
   //your code starts from her
   ll n;
   char c;
   cin>>n>>c;
 
   string s;
   cin>>s;
   
   ll val = count(all(s),c);
   ll notval = n- val;
   if(val==n){
   	cout<<0<<endl;
   	return;
   }
   
   for(ll i=1;i<n+1;i++){
   	ll cnt = 0;
   	for(ll j = i;j<n+1;j+=i){
   		if(s[j-1]!=c ){
   			cnt++;
   		}
   	}
   	if(cnt == 0){
   		cout<<1<<endl;
   		cout<<i<<endl;
   		return;
   	}
   	
   }
   
   cout<<2<<endl;
   cout<<n<<" "<<(n-1)<<endl;
   
   
   
}
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