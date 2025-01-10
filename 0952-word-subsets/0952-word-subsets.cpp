class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        vector<int> freq2(26,0);

        for(string s:words2)
        {
            vector<int> temp(26,0);
            for(char c:s)
            {
                temp[c-'a']++;
                freq2[c-'a']=max(freq2[c-'a'],temp[c-'a']);
            }
        }

        vector<int> freq1(26,0);
        for(string s:words1)
        {
            vector<int> temp(26,0);
            for(char c:s)
            {
                temp[c-'a']++;
            }
            bool check=true;
            for(int i=0;i<26;i++)
            {
                if(freq2[i]>0 && temp[i]<freq2[i])
                {
                    check=false;
                }
            }
            if(check)
            {
                result.push_back(s);
            }
        }
        return result;
    }
};