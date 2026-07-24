class Solution {
public:
int mx = 3000;
    int uniqueXorTriplets(vector<int>& v) {
        vector<bool>freq(mx, 0);
        int n = v.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++) freq[v[i]^v[j]] = 1;
        }
        freq[0] = 1;
        vector<bool>freq2(mx, 0);
        for(auto &j: v){
            for(int i=0; i<mx; i++){
                if(freq[i]) freq2[i^j] = 1;
            }
        }
        int c = 0;
        for(int i=0; i<mx; i++){
            c += freq2[i];
        }
        return c;
    }
};