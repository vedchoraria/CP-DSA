class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long m = 1LL*mass;
        for(int i : asteroids){
            if(i > m) return false;
            m += i; 
        }
        return true;
    }
};