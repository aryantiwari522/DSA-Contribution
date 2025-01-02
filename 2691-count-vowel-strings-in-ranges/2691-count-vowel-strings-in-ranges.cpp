class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> marks(words.size(),0);
        vector<int> ans;
        int i=0;
        for(string s: words)
        {
            int last=s.length()-1;
            if((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') && (s[last] == 'a' || s[last] == 'e' || s[last] == 'i' || s[last] == 'o' || s[last] == 'u'))
            {
                    marks[i]=1;
            }
            i++;
        }
        vector<int> prefixSum(marks.size() + 1, 0);
        for (i = 0; i < marks.size(); i++) {
            prefixSum[i + 1] = prefixSum[i] + marks[i];
        }
        for(const auto& pair:queries)
        {
            int start=pair[0];
            int end=pair[1];
            ans.push_back(prefixSum[end + 1] - prefixSum[start]);
        }
        return ans;
    }
};