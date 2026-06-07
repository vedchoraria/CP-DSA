class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int i=0;
        int n=asteroids.size();
        long long s=mass;
        while(i<n){
            if(s<asteroids[i]) return false;
            else{
                s=s+asteroids[i];
            }
            i++;
        }
        return true;
    }
};