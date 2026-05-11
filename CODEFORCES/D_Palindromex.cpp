//Author : VED CHORARIA
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
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
    return __gcd(a,b) == 1;
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
void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> b(2*n); 
    cin(b);
    int p1 =-1 , p2 =-1;
    for(int i=0;i<2*n;i++){
        if(b[i]==0){
            if(p1 == -1) p1 = i;
            else p2 = i;
        }
    }
    int ans = 0;
    //BASIC vector to keep track which is missing
    vector<int>cnt1(n+2,0);
    //CASE 1 : expanding around p1
    int i = p1 , j = p1;
    while(i>=0 && j < 2*n){
        if(b[i] == b[j]){cnt1[b[i]]++; i--; j++;}
        else break;
    }
    for(int k=0;k<n+2;k++){
        if(cnt1[k] == 0) {ans = max(ans, k); break;
    }}

    //CASE 2 : expanding around p2;
    vector<int>cnt2(n+2,0);
    i = p2 , j = p2;
    while(i>=0 && j < 2*n){
        if(b[i] == b[j]){cnt2[b[i]]++; i--; j++;}
        else break;
    }
    for(int k=0;k<n+2;k++){
        if(cnt2[k] == 0) {ans = max(ans, k); break;
    }}

    //CASE3: p1 , p2 two ends
    vector<int>cnt3(n+2,0);
    bool val = true;
    i = p1 , j = p2;
    while(i<=j){
        if(b[i] == b[j]){cnt3[b[i]]++; i++; j--;}
        else {val = false; break;}
    }
    if(val){
            while(i>=0 && j < 2*n){
                if(b[i] == b[j]){cnt3[b[i]]++; i--; j++;}
                else break;
            }
            for(int k=0;k<n+2;k++){
                if(cnt3[k] == 0) {ans = max(ans, k); break;}
            }
    }
    print(ans);
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