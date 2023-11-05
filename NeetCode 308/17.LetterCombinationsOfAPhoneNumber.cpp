class Solution {
public:

    /*
        Problem:
          Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
          A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

        Approach:
            1. First we must created a mapping of all possible characters per digit
            2. we will then use this mapping, combined with backtracking, to get all 
                possible combinations of a string of digits
    
    */

    // recursive backtracking helper function
    void getCombinations(vector<string>& res, string digits, unordered_map<int, vector<char>>& map, string curr_combination, int index) {

        if(index >= digits.length()) {
            res.push_back(curr_combination);
            return;
        }

        // go through all characters in the current digit and get all combinations
        int digit = digits[index] - '0';
        for(int i = 0; i < map[digit].size(); i++) {
            curr_combination += map[digit][i];
            getCombinations(res, digits, map, curr_combination, index + 1);
            curr_combination.pop_back(); // backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        

        // create mapping for all digits
        unordered_map<int, vector<char>> digit_mappings;
        digit_mappings[2] = {'a', 'b', 'c'};
        digit_mappings[3] = {'d', 'e', 'f'};
        digit_mappings[4] = {'g', 'h', 'i'};
        digit_mappings[5] = {'j', 'k', 'l'};
        digit_mappings[6] = {'m', 'n', 'o'};
        digit_mappings[7] = {'p', 'q', 'r', 's'};
        digit_mappings[8] = {'t', 'u', 'v'};
        digit_mappings[9] = {'w', 'x', 'y', 'z'};


        vector<string> all_combinations;
        if(digits == "") return all_combinations; // edge case
        string current_combination = "";

        // perform backtracking algorithmn
        getCombinations(all_combinations, digits, digit_mappings, current_combination, 0);
        return all_combinations;



    }
};
