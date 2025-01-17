class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int XOR=0;
        for(int n:derived)
        {
            XOR^=n;
        }
        if(XOR==0)
        {
            return true;
        }
        return false;
    }
};