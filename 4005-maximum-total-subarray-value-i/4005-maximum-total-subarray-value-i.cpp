class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxm=LLONG_MIN;
        long long minm=LLONG_MAX;
        for(int n:nums){
            if(n<=minm){
                minm=n;
            }
            if(n>=maxm) maxm=n;
        }
        return (maxm-minm)*k;
    }
};