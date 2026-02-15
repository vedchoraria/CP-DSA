#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int p[n];
        for(int i=0;i<n;i++){
            cin>>p[i];
        }
        int x;
        int i=0;
        for(i;i<n;i++){
            if(p[i]!=i){
                x=p[i];
                break;
            }
        }
        i++;
        for(i;i<n;i++){
            if(p[i]!=i)x=x&p[i];
        }
        cout<<x<<endl;
    }
}