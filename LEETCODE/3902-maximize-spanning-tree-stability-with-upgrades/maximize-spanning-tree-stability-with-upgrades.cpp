class disjointSet{
    vector<int>par, size;
    public:
    disjointSet(int n){
        par.resize(n);
        size.resize(n);
        for(int i=0; i<n; i++){
            par[i] = i;
            size[i] = 1;
        }
    }
    int ultimatePar(int n){
        if(par[n] == n) return n;
        par[n] = this->ultimatePar(par[n]);
        return par[n];
    }
    void unionBySize(int u, int v){
        int ulp_u = this->ultimatePar(u);
        int ulp_v = this->ultimatePar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] > size[ulp_v]){
            par[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }else{
            par[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};
class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        auto poss = [&](int mid){
            int kl = k, ec = 0;
            disjointSet* ds = new disjointSet(n);
            // must edges
            for(auto &i: edges){
                if(i[3] == 0) continue;
                int u = i[0], v = i[1];
                int s = i[2];
                if(s < mid) return false;
                if(ds->ultimatePar(u) == ds->ultimatePar(v)) return false;
                ds->unionBySize(u,v);
                ec++;
            }
            // edges that don't require upgrade
            for(auto &i: edges){
                if(i[3]) continue;
                int s = i[2], u = i[0], v = i[1];
                if(ds->ultimatePar(u) != ds->ultimatePar(v) && s>= mid){
                    ds->unionBySize(u,v);
                    ec++;
                }
            }
            // edges that require upgrade
            for(auto &i: edges){
                if(i[3]) continue;
                int s = i[2], u = i[0], v = i[1];
                if(ds->ultimatePar(u) != ds->ultimatePar(v) &&
                     (kl && 2*s >= mid)){
                    ds->unionBySize(u,v);
                    if(s < mid) kl--;
                    ec++;
                }
            }
            return ec == n-1;
        };
        int l = -1, r = 1e6, mid;
        // cout<<poss(95)<<endl;
        while(r-l>1){
            mid = l+(r-l)/2;
            if(poss(mid)) l = mid;
            else r = mid;
        }
        return l;
    }
};