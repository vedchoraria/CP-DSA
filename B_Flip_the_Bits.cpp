#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string a,b; cin>>a>>b;
        vector<bool>canflip(n);
        int c0=0,c1=0;
        for(int i=0;i<n;i++){
            if(a[i]=='0')c0++;
            else c1++;
            if(c0==c1)canflip[i]=true;
        }
        bool isflip=false,ans=true;
        for(int i=n-1;i>=0;i--){
            if(isflip==false){
                if(a[i]!=b[i]){
                    if(canflip[i]==true)isflip^=true;
                    else{
                        ans=false;
                        break;
                    }
                }
            }
            else{
                if(a[i]==b[i]){
                    if(canflip[i]==true)isflip^=true;
                    else{
                        ans=false;
                        break;
                    }
                }
            }
        }
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}