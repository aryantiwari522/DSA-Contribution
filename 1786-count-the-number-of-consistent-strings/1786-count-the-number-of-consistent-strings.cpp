class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> idx(26,0);
        for(char c: allowed)
        {
            idx[c-'a']++;
        }
        int count=0;
        bool flag=true;
        for(string s: words)
        {
            for(char c:s)
            {
                if(idx[c-'a']==0)
                {
                    flag=false;
                    break;
                }
            }
            if(flag){
                count++;
            }
            flag=true;
        }
    return count;
    }
};