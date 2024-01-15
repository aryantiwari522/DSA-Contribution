class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> playersWithZeroLoss;
        unordered_map<int, int> loserPlayer;

        for (auto& match : matches) {
            int winner = match[0];
            playersWithZeroLoss.insert(winner);
        }

        for (auto& match : matches) {
            int loser = match[1];
            playersWithZeroLoss.erase(loser);
            loserPlayer[loser]++;
        }

        vector<int> playerLoseOneTime;
        for (auto loser : loserPlayer) {
            int freq = loser.second;
            if (freq == 1) {
                playerLoseOneTime.push_back(loser.first);
            }
        }
        sort(playerLoseOneTime.begin(), playerLoseOneTime.end());
        vector<vector<int>> answer;
        answer.push_back(vector<int>(playersWithZeroLoss.begin(),
                                     playersWithZeroLoss.end()));
        answer.push_back(playerLoseOneTime);
        return answer;
    }
};