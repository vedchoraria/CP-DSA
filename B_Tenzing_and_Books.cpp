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
    int x; cin>>x;
    vector<int> a(n) , b(n) , c(n); 
    cin(a); cin(b); cin(c);
    int ans = 0;
    int i = 0;
    while(i<n){
        if((x | a[i]) == x) ans |= a[i];
        else break;
        i++;
    }

    i = 0;
    while(i<n){
        if((x | b[i]) == x) ans |= b[i];
        else break;
        i++;
    }

    i = 0;
    while(i<n){
        if((x | c[i]) == x) ans |= c[i];
        else break;
        i++;
    }

    if(ans == x) {print("Yes");}
    else print("No");
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