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
ll int mod = 998244353;
void solve() {
    
    
    string s; cin>>s;
    int n = s.length();
    ll ans1 =0 , ans2 = 1;
    ll cnt =1;
    ll tot = 1;
    for(ll i  =1 ; i<n;i++){
        if(s[i] == s[i-1]) cnt++;
        else{
            tot++;
            ans1 += cnt-1;
            ans2 = (ans2*cnt)%mod;
            cnt = 1;
        }
    }
    if(cnt>1) ans1 += cnt-1;
    ans2 = (ans2*cnt)%mod;
    
    //Now joh delete krna hai usme bhi toh order diff ho sakta hai...that's why multiply by factorial of tot
    // or tot = correct no of characters

    tot = n - tot;
    //now represents no of charaters to be removed 

    for(int i =1 ;i<= ans1 ;i++){
        ans2 = (ans2*i)%mod;
    }
    cout<<ans1<<" "<<ans2<<endl;

    // Solve logic here
    
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