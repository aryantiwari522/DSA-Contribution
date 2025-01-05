class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> mark(n + 1, 0); 
        for (const vector<int>& v : shifts) {
            int start = v[0], end = v[1], direction = v[2];
            mark[start] += (direction == 1) ? 1 : -1;
            mark[end + 1] += (direction == 1) ? -1 : 1;
        }
        for (int i = 1; i < n; ++i) {
            mark[i] += mark[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            int shift = mark[i] % 26;
            s[i] = (s[i] - 'a' + shift + 26) % 26 + 'a';
        }
        return s;
    }
};
