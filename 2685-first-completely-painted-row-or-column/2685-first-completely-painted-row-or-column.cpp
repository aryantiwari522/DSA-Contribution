class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]=i;
        }
        int minIndx=INT_MAX;
        for(int row=0;row<m;row++)
        {
            int maxIndx=INT_MIN;
            for(int col=0;col<n;col++)
            {
                int val=mat[row][col];
                int indx=mp[val];
                maxIndx=max(maxIndx,indx);
            }
            minIndx=min(minIndx,maxIndx);
        }

        for(int col=0;col<n;col++)
        {
            int maxIndx=INT_MIN;
            for(int row=0;row<m;row++)
            {
                int val=mat[row][col];
                int indx=mp[val];
                maxIndx=max(maxIndx,indx);
            }
            minIndx=min(minIndx,maxIndx);
        }
        return minIndx;
    }
};