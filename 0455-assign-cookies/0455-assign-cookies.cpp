class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int contentChildren = 0;
        int i = 0; // Index for greed factors
        int j = 0; // Index for cookie sizes

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                // Cookie size is sufficient for the child's greed
                contentChildren++;
                i++;
            }
            j++; // Move to the next cookie
        }

        return contentChildren;
    }
};