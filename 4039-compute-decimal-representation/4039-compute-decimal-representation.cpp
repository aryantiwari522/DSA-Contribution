class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        string s = to_string(n);
        vector<int> result;

        int len = s.size();
        for (int i = 0; i < len; i++) {
            int digit = s[i] - '0';
            if (digit > 0) {
                int place = pow(10, len - i - 1);
                result.push_back(digit * place);
            }
        }
        return result;
    }
};