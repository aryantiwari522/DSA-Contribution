class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> mp;
        int min_Value=INT_MAX;
        long long result=0;
        for(int c1:basket1){
            mp[c1]++;
            min_Value=min(c1,min_Value);
        }

        for(int c2:basket2){
           mp[c2]--;
           min_Value=min(c2,min_Value);
        }

        vector<int> v;

        for(auto &it:mp)
        {
            int element=it.first;
            int freq=it.second;

            if(freq==0) continue;
            if(freq%2 != 0) return -1;
            for(int i=0;i<abs(freq)/2;i++)
            {
                v.push_back(element);
            }
        }
        //sort(v.begin(), v.end()); T.C is nlog(n).

        //now i am going to use nth_element algorithm, it T.C is o(n).
        nth_element(v.begin(), v.begin()+v.size()/2 ,v.end());

        for(int i=0;i<v.size()/2;i++)
        {
            result+=min(v[i],min_Value*2);
        }
        return result;
    }
};