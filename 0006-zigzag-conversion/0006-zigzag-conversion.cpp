class Solution {
public:
    string convert(string s, int numRows) {
        string result="";
        vector<string> arr(numRows,"");
        int i=0;
        while(i<s.length())
        {
            for(int index=0;index<numRows && i<s.length();index++)
            {
                arr[index]+=s[i++];
            }
            for(int index=numRows-2;index>0 && i<s.length();index--)
            {
                arr[index]+=s[i++];
            }
        }
        for(string str:arr)
        {
            result+=str;
        }
        return result;
    }
};