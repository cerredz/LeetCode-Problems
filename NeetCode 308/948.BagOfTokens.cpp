class Solution {
public:
/*
  Problem:
      You start with an initial power of power, an initial score of 0, and a bag of tokens given as an integer array tokens, where each tokens[i] denotes the value of tokeni.
      Your goal is to maximize the total score by strategically playing these tokens. In one move, you can play an unplayed token in one of the two ways (but not both for the same token):
      Face-up: If your current power is at least tokens[i], you may play tokeni, losing tokens[i] power and gaining 1 score. Face-down: If your current score is at least 1, you may play tokeni, 
      gaining tokens[i] power and losing 1 score. Return the maximum possible score you can achieve after playing any number of tokens.

*/
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size() == 0) return 0;
        // sort the tokens (we want to face-up the lowest tokens and face-down the highest tokens)
        sort(tokens.begin(), tokens.end());
        if(tokens[0] > power) return 0;
        int left = 0, right = tokens.size() - 1;
        int score = 0, current_score = 0;
        // using a two-pointer approach, face-up all of the lowest tokens and face-down all of the highest tokens, while staying in the parameters of the game described
        while(left <= right) {
            int lowest_token = tokens[left];
            int highest_token = tokens[right];
            if(lowest_token <= power) {
                // have enough power to take lowest token available, decrease our power and move our pointer to the next lowest token
                power -= lowest_token;
                current_score += 1;
                left++;
            } else if(current_score == 0) {
                // cannot take a high token face-down since score == 0, so just return highest score we have found so far
                return score;
            } else {
                // do not have enough power, take highest token face-down
                power += highest_token;
                right--;
                current_score -= 1;
            }
            score = max(score, current_score);
        }
        return score;
    }
};
