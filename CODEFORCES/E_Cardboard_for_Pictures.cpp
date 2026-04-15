//Author : VED CHORARIA
#include <bits/stdc++.h>
using namespace std;
#include<cmath>
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
    int n; cin>>n;
        long  double c; cin>>c;
        int s[n];
        long  double b=0;
        for(int i=0;i<n;i++){
            cin>>s[i];
            b+=2*s[i];
            c-=s[i]*s[i];
        }
        c=c*(-1);
        long  double a=n;
        long  double ans=max(((-b)-sqrt(b*b-4*a*c))/(2*a),((-b)+sqrt(b*b-4*a*c))/(2*a));
        cout<<(long long)ans/2<<endl;
    
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