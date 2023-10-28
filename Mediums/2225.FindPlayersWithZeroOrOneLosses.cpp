class Solution {
public:

    /*
      Problem:
        You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.
        Return a list answer of size 2 where: answer[0] is a list of all players that have not lost any matches. answer[1] is a list of all players that have lost exactly one match.
        The values in the two lists should be returned in increasing order.  Note: You should only consider the players that have played at least one match.  The testcases will be generated
        such that no two matches will have the same outcome.

    */
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {

        // count the number of times each player has lost using a hashMap
        int n = matches.size();
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            int loser = matches[i][1];
            mp[loser]++;
        }

        // build the two lists using the hashMap
        vector<int> noLoss;
        vector<int> oneLoss;

        // count players who have not lost
        for(int i = 0; i < n; i++) {

            int winner = matches[i][0];
            if(mp[winner] == 0) {
                noLoss.push_back(winner);
                mp[winner] = -1; // dont want to count no losses twice
            }
        }

        // count players with 1 loss
        for(auto entry : mp) {
            if(entry.second == 1) {
                oneLoss.push_back(entry.first);
            }
        }
        
        sort(noLoss.begin(), noLoss.end());
        return {noLoss, oneLoss};



    }
};
