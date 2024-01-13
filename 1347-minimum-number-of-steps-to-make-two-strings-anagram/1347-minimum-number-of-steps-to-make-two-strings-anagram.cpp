class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> letterS;
        int l=s.length();
        for(char c: s)
        {
            letterS[c]++;
        }
        unordered_map<char,int> letterT;
        for(char c: t)
        {
            letterT[c]++;
        }
        int sum=0;
        for (const auto& pair : letterS) {
        char ch = pair.first;
        int countS = pair.second;

        auto it=letterT.find(ch);
        if(it!=letterT.end())
        {
            int countT=it->second;
            if(countT<countS)
                sum+=(countS-countT);
        }
        else
        {
            sum+=countS;
        }
        }
        return sum;


    //     unordered_map<char, int> countMap;

    // // Count occurrences of characters in string s
    // for (char c : s) {
    //     countMap[c]++;
    // }

    // // Subtract occurrences of characters in string t
    // for (char c : t) {
    //     countMap[c]--;
    // }

    // int minSteps = 0;

    // // Sum up absolute differences in occurrences
    // for (auto& entry : countMap) {
    //     minSteps += abs(entry.second);
    // }

    // return minSteps / 2;
    }
};