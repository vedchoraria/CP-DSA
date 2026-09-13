class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        /*
        specific part of matrix remains same
        n = 30
        n^4 = 8.1*1e5 * 900  = 10^8.8 bruteforce wont work
        n = 30 
        we can represnt in form of nums
        */
        int n = img1.size();
        vector<int>base, match;
        for(int i=0; i<n; i++){
            int nm = 0, nm2 = 0;
            for(int j=0; j<n; j++){
                nm <<= 1;
                if(img1[i][j]) nm |= 1;
                nm2 <<= 1;
                if(img2[i][j]) nm2 |= 1;
            }
            base.push_back(nm);
            match.push_back(nm2);
        }
    
        vector<int>temp(n);
        auto get = [&]() -> int {
            int mx = 0;
            for(int i=0; i<n; i++){
                for(int j=i; j<n; j++){
                    int len = j-i+1;
                    int cnt = 0, id = i;
                    for(int k=0; k+len-1<n; k++){
                        id = i;
                        cnt = 0;
                        for(int l=k; l<k+len; l++, id++){
                            cnt += __builtin_popcount(temp[id] & match[l]);
                        }
                        mx = max(mx, cnt);
                    }
                }
            }
            return mx;
        };
        int mx = 0;
        for(int i=0; i<=n-1; i++){
            // right shift
            for(int j=0; j<n; j++) temp[j] = base[j]>>i;
            mx = max(mx, get());
        }
        for(int i=1; i<=n-1; i++){
            // left shift
            for(int j=0; j<n; j++) temp[j] = base[j]<<i;
            mx = max(mx, get());
        }
        return mx;
    }
};