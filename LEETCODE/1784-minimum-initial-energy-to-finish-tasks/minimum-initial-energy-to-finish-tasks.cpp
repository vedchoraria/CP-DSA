class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        //pq
        int start = 0; int ans =0;
        priority_queue<pair<int,pair<int,int>>>pq;
        for(auto it : tasks){
            pq.push({it[1]-it[0] , {it[0],it[1]}});
        }
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            ans += max(0,it.second.second - start);
            start = max(start, it.second.second);
            // cout<< "  A : "<<it.first
            // <<"  b : "<< it.second.first<<
            // "  c  : "<<it.second.second<<
            // "  ANS : "<<ans<<
            // "  START : "<<start<<endl;
            start -= it.second.first;
        }
        return ans;
    }
};