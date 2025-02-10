class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        string ans="";
        for(char c:s)
        {
            if(isdigit(c) && !st.empty()) st.pop();
            if(!isdigit(c)) st.push(c);
        }
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};