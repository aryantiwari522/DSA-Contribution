class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) {
            return false;
        }
        vector<int> freq(26,0);
        int sum=0;
        for(char c:s)
        {
            freq[c-'a']++;
        }
        for(int n:freq)
        {
            if(n%2!=0){
            sum++;
            }
        }
        return sum<=k;
    }
};