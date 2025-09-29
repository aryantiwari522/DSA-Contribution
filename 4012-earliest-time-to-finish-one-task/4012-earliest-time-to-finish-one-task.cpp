class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int minm=INT_MAX;
        for(vector<int> t:tasks){
            minm=min(minm,(t[0]+t[1]));
        }
        return minm;
    }
};