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
    int n,k;
    if (!(cin >> n)) return;
    cin>>k;
    vector<int> b(n); 
    cin(b);
    int total = 0;
    unordered_map<int,int>mpp;
    for(int &i : b){
        total += i;
        mpp[i]++;
    }
    bool hai = false;
    // for(int &i : b){
        int a = (k + total)/2;
        if(mpp[a] >=1){
            hai = true;
            // break;
        }
    // }
    // Solve logic here
    if(hai) {print("Yes");}
    else {print("no");}
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