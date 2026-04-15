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

void print_arr(vector<int> v){
    for(int &i : v) cout << i << " "; cout<<endl;
}
// --- Constants ---
const int MOD = 1e9 + 7;
const ll INF = 1e18; // Changed to ll to match 1e18

// --- General Functions ---
bool isCo_Prime( int a , int b){
    return true ? gcd(a,b) == 1 : false;
}

// --- Logic ---
void solve() {
    string s; cin>>s;
        long long int n=s.length();
        s+=s;
        long long int maxc=0,c=0,c0=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')c++;
            else{
                c=0;
                c0=1;
            }
            maxc=max(maxc,c);
        }
        if(c0==0){
            cout<<n*n<<endl;
        }
        else {
            if(maxc%2)cout<<((maxc/2)+1)*((maxc/2)+1)<<endl;
            else cout<<((maxc/2)+1)*(maxc/2)<<endl;
        }
    
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