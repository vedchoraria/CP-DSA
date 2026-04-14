class Solution {
public:
    int getMinDistance(vector<int>& v, int t, int st) {
        int mn = 1e5, n = v.size();
        for(int i=0; i<n; i++) if(v[i] == t) mn = min(abs(st-i), mn);
        return mn;
    }
};