class Solution {
    public int maxRotateFunction(int[] nums) {
        int n=nums.length;
        //f(1)=f(0)+sum(nums)-(n*(n-i))
        int f=0,sum=0;
        for(int i=0;i<n;i++)
        {
            f += i*nums[i];
            sum += nums[i];
        }
        int maxm=f;
        int ans =0;
        for(int rotate=1;rotate<n;rotate++)
        {
            f = f + sum - (n*nums[n-rotate]);
            maxm = Math.max(maxm,f);
        }
        return maxm;
    }
}