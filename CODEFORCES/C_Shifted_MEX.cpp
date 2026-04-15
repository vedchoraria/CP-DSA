#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        long long int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        bool incre=false;
        int maxl=0,l=0;
        sort(a,a+n);
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]+1){
                l++;
                incre=true;
            }
            else if(a[i]!=a[i-1]){
                incre=false;
                l=0;
            }
            maxl=max(maxl,l);
        }
        cout<<maxl+1<<endl;
    }
}