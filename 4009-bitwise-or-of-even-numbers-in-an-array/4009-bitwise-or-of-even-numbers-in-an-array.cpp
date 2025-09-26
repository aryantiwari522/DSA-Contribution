class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int res=0;
        for(int n:nums){
            if(n%2==0)
            {
            res |=n;
            }
        }
        return res;
    }
};