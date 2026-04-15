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

// --- Logic ---
void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> b(n); 
    cin(b);
    int i = 0 , j = n - 1;
    if(n == 1) {
        print(0);
        return;
    }
    int ans = INT_MIN;
    while(i<j){
        if(i == j) break;

        ans = max(ans , abs(b[i] - b[j]));
        i++;
        j--;
    }

    for(int &it : b)
    it=it%ans;
    for(int k = 0 ; k < n/2 ; k++){
        if(b[k] != b[(n/2)-k+1]) {
            print(0);
            return;
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