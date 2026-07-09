class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>dsu(n);
        int com=0;
        dsu[0]=0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=maxDiff)dsu[i]=com;
            else{
                com++;
                dsu[i]=com;
            }
        }
        int m=queries.size();
        vector<bool>ans(m);
        int i=0;
        for(auto& it:queries){
            if(dsu[it[0]]==dsu[it[1]])ans[i++]=true;
            else ans[i++]=false;
        }
        return ans;
    }
};