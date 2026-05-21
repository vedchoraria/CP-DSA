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
#define print_arr(x) for(int &i : (x)) cout << i << " "; cout<<endl;
#define pys cout<<"YES\n"
#define pno cout<<"NO\n"


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

int findMaxBitPosition(int n) {
    if (n == 0) {
        return 0; // No set bits
    }
    int position = 0;
    while (n != 0) {
        n >>= 1;      // Right shift n by 1
        position++;   // Increment position counter
    }
    return position;
}
void printPrimeFactors(long long n) {
    // Print the number of 2s that divide n
    while (n % 2 == 0) {
        std::cout << 2 << " ";
        n = n / 2;
    }

    // n must be odd at this point. So we can skip one element (i=3) and 
    // increment i by 2 (i=5, 7, 9, ...)
    for (long long i = 3; i * i <= n; i = i + 2) {
        // While i divides n, print i and divide n
        while (n % i == 0) {
            std::cout << i << " ";
            n = n / i;
        }
    }

    // If n is a prime number greater than 2, it will not become 1 by the above loops
    if (n > 2) {
        std::cout << n << " ";
    }
}

long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

//LCM FUnc
// --- Logic ---
auto helper(int x) {
    map<int,ll> path;
    ll cost = 0;
    while (!path.count(x)) {
        path[x] = cost++;      
        if(x & 1) x++;
        else x /= 2;
    }
    return path;
}

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    cin(a);
    map<int,ll>temp = helper(a[0]);
    for(int i=1; i<n && !temp.empty(); i++) {
        map<int,ll>mpp;
        map<int,ll>hey;
        ll cost = 0;
        int j = a[i];
        while(!mpp.count(j)){
            mpp[j] = cost;
            if(temp.count(j))
                hey[j] = temp[j] + cost; 
            if (j & 1) j++;
            else j /= 2;
            cost++;
        }
        temp = move(hey);
    }

    ll ans = LLONG_MAX;
    for(auto& [v, c] : temp) ans = min(ans, c);
    print(ans);
}


int main() {
    fastio;
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int t = 1;
    cin >> t; 

    // dp[0] = 0;
    // dp[1] = 0;
    // for(ll i = 2;i<=1e9;i++){
    //     if(i&1) dp[i] = dp[(i+1)/2] +2;
    //     else dp[i] = dp[i/2] +1;
    // }


    while (t--) {
        solve();
    }
    return 0;
}