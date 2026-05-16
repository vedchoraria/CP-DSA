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
void solve(){
    ll a;
    int n;
    cin>>a>>n;
    int x,y;
    cin>>x>>y;
    ll ans=2e18;
    string s=to_string(a);
    int l=s.size();
    if(x==0) ans=min(ans,a);
    for(int len=1;len<=18;len++){
        int first=(x==0 && len>1)?y:x;
        ll d1=first;
        for(int j=1;j<len;j++)
            d1=d1*10+x;
        ll d2=0;
        for(int j=0;j<len;j++)
            d2=d2*10+y;
        if(len<l){
            ans=min(ans,a-d2);
        }
        else if(len>l){
            ans=min(ans,d1-a);
            break;
        }
        else{
            bool ok=true;
            for(int p=0;p<len && ok;p++){
                int cur=s[p]-'0';
                for(int k=1;k>=0;k--){
                    int d=(k?y:x);
                    if(p==0 && d==0 && len>1)
                        continue;
                    if(d<cur){
                        ll b=0;
                        for(int j=0;j<p;j++)
                            b=b*10+(s[j]-'0');
                        b=b*10+d;
                        for(int j=p+1;j<len;j++)
                            b=b*10+y;
                        ans=min(ans,a-b);
                        break;
                    }
                }
                for(int k=0;k<2;k++){
                    int d=(k?y:x);
                    if(p==0 && d==0 && len>1)
                        continue;
                    if(d>cur){
                        ll b=0;
                        for(int j=0;j<p;j++)
                            b=b*10+(s[j]-'0');
                        b=b*10+d;
                        for(int j=p+1;j<len;j++)
                            b=b*10+x;

                        ans=min(ans,b-a);
                        break;
                    }
                }

                if(cur!=x && cur!=y)
                    ok=false;
            }
            if(ok) ans=0;
        }
    }

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
    while (t--) {
        solve();
    }
    return 0;
}