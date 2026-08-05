class Solution {
    int fa[100005];
    int f(int a) {return fa[a] = (fa[a] == a) ? a : f(fa[a]);}
    void unite(int a, int b) {fa[f(a)] = f(b);}
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& ed) {
        vector<int> adj[n];
        for(int i=0; i<n; i++) fa[i] = i;
        for(auto &i: ed){
            adj[i[0]].push_back(i[1]);
            unite(i[0], i[1]);
        }
        vector<bool>vis(n, 0);
        queue<int>q;
        q.push(k);
        vis[k] = 1;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(auto &ch: adj[t]){
                if(!vis[ch]){
                    vis[ch] = 1;
                    q.push(ch);
                }
            }
        }
        vector<int>ans;
        for(auto &i: ed){
            int u = i[0], v = i[1];
            if(vis[u]^vis[v]){
                for(int j=0; j<n; j++){
                    ans.push_back(j);
                }
                return ans;
            }   
        }
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};