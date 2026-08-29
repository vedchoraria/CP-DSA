class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>mpp;
        int n = position.size();
        for(int i = 0 ; i<n;i++){
            mpp.push_back({position[i], speed[i]});
        }
        sort(mpp.rbegin(), mpp.rend());
        double time = 0;
        int ans =0;
        for(int i=0;i<n;i++){
            double t = (double)(target - mpp[i].first)/(double)mpp[i].second;
            if(t>time) ans++;
            cout<<t<<" "<<time<<endl;
            time = max(t,time);
            
        }
        return ans;
    }
};