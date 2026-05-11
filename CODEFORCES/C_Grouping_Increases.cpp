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
// void solve() {
//     int n;
//     if (!(cin >> n)) return;
    
//     vector<int>a(n);
//     int mi = 1e8;

//     for(int i =0;i<n;i++){
//         cin>>a[i]; mi = min(mi , a[i]);
//     }

//     vector<int>t;
//     int top = mi;
//     int i = n-1;
//     while(i>=0){
//         if(a[i] == mi) break;
//         else{
//             t.pb(a[i]);
//         }

//         i--;
//     }
//     for(i ;i>=0;i--){
//         if(a[i] >= top){
//             top = a[i];
//         }
//         else{
//             t.pb(a[i]);
//         }
//     }

//     int cnt =0;
//     for(int j =t.size()-2;j>=0;j--){
//         if(t[j] > t[j+1]) cnt++;
//     }

//     print(cnt);
//     // print_arr(t);
//     // Solve logic here
    
// }

void solve(){
    int n;
    cin>>n;
    vector<int>b(n);
    cin(b);
    int ans = 0; // total penalty accumulated across both subsequences
	int x = INT_MAX, y = INT_MAX; // current last elements (tails) of the two subsequences; we maintain x <= y

	for (int i = 0; i < n; i++) {
		if (x > y) {
			swap(x, y); // keep invariant x <= y before placing a[i]
		}
		// Greedily place a[i] into the leftmost subsequence it can extend without increasing its last value.
		if (b[i] <= x) {
			x = b[i]; // extend first subsequence (non-increasing), no new increase
		} else if (b[i] <= y) {
			y = b[i]; // extend second subsequence, no new increase
		} else {
			// a[i] is greater than both tails: we must start a new group in one subsequence,
			// which contributes +1 to the penalty.
			x = b[i];
			ans++;
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