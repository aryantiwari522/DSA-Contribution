class Solution {
public:
    int minimumLength(string s) {
     vector<int> freq(26,0);
     int count=0;
     for(char c:s)
     {
        freq[c-'a']++;
     }
     for(int i=0;i<26;i++)
     {
        while(freq[i]>=3)
        {
            freq[i]-=2;
        }
        if(freq[i]>0)
        {
            count+=freq[i];
        }
     }
     return count;
    }
};