class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int start = 0;
        int ans = 0;
        for(int i : requests){
            ans += abs(i-start);
            start = i;
        }
        return ans;
    }
};