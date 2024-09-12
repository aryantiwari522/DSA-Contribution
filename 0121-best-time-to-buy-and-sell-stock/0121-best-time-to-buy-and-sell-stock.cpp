class Solution {
public:
    int maxProfit(vector<int>& prices) {
           int n=prices.size();
       if(n==1) return 0;
       int cur_prof=0, max_prof=0;
       for(int i=n-2; i>=0; --i){
           cur_prof=prices[i+1]-prices[i]+cur_prof;
           if(cur_prof<0) cur_prof=0;
           max_prof=max(max_prof, cur_prof);
       }
       return max_prof;
   }
};