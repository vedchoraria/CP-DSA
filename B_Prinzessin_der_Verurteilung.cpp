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

//LCM FUnc
void two(string s , bool &found){
    int n = s.length();
    unordered_map<string,int>mpp;
    for(int i=0;i<n-1;i++){
        // cout<<i<< " : "<<s.substr(i,i+2)<<" ";
        string z = s;
        string abc = z.substr(i,2);
        // cout<<i<<" : "<<abc<<endl;        
        mpp[abc]++;
    }
    for(int i=0;i<26;i++){
        char first = i+'a';
        for(int j = 0; j<26;j++){
            char second = j+'a';
            string c ="";
            c.pb(first); c.pb(second);
            // print(c);
            if(!mpp[c]){
                print(c); 
                found = true; return;
            }
        }
    }
}
void three(string s , bool &found){
    int n = s.length();
    if(found) return;
    unordered_map<string,int>mpp;
    for(int i=0;i<n-1;i++){
        // cout<<i<< " : "<<s.substr(i,i+2)<<" ";
        string z = s;
        string abc = z.substr(i,3);
        // cout<<i<<" : "<<abc<<endl;        
        mpp[abc]++;
    }
    for(int i=0;i<26;i++){
        char first = i+'a';
        for(int j = 0; j<26;j++){
            char second = j+'a';
            for(int k =0;k<26;k++){
                string c ="";
                char third = k+'a';
                c.pb(first); c.pb(second); c.pb(third);
                // print(c);
                if(!mpp[c]){
                   print(c); return;
                }
            }
        }
    }
}
// --- Logic ---
void solve() {
    int n;
    if (!(cin >> n)) return;
    string s; cin>>s;
    vector<bool>one(26,0);
    for(char c : s) one[c-'a'] = true;
    for(int i=0; i<26;i++){
        if(one[i] == false){
            char c = i+'a';
            print(c); return;}

    }
    bool found = false;
    // 2 Members
    two(s , found);
    //3 members: 
    three(s , found);

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