class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()) return false;

        vector<int> freq(26,0);
        bool dup=false;
        for(char c:s)
        {
            freq[c-'a']++;
            if(freq[c-'a']>1){
                dup=true;
                break;
            }
        }

        if(s==goal && dup)
        {
            return true;
        }

        vector<int> diffIndx;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=goal[i])
                diffIndx.push_back(i);
        }
        

        return (diffIndx.size()==2 && (s[diffIndx[0]] == goal[diffIndx[1]] && s[diffIndx[1]] == goal[diffIndx[0]]));
    }
};