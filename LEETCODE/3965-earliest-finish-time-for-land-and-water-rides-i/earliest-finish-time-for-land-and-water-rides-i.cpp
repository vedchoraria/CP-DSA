class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        // first land 
        set<int>landFinishTime;
        int mi_land = INT_MAX;
        for(int i =0; i < n; i++){
            landFinishTime.insert(landStartTime[i] + landDuration[i]);
            mi_land = min(mi_land, landStartTime[i] + landDuration[i]);
        }

        int ans1 = INT_MAX;
        for(int i =0; i< m;i++){
            if(waterStartTime[i] >= mi_land){
                ans1 = min(ans1, waterStartTime[i] + waterDuration[i]);
            }
            else{
                ans1 = min(ans1, mi_land + waterDuration[i]);
            }
        }

        //first water
        int mi_water = INT_MAX;
        for(int i =0 ;i < m; i++){
            mi_water = min(mi_water, waterStartTime[i] + waterDuration[i]);
        }

        int ans2 = INT_MAX;
        for(int i =0; i< n;i++){
            if(landStartTime[i] >= mi_water){
                ans2 = min(ans2, landStartTime[i] + landDuration[i]);
            }
            else{
                ans2 = min(ans2, mi_water + landDuration[i]);
            }
        }

        return min(ans1, ans2);


    }
};