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
    bool fodd = true ? b[0] % 2 != 0 : false;

    for(int i =1 ;i<n;i++){
        
            if(fodd && b[i]% 2 != 0 ){
                print("No");
                return;
            }
            if(!fodd && b[i] %2 == 0){
                print("No");
                return;
            }
        fodd = !fodd;
    }
    // Solve logic here
    print("Yes");
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