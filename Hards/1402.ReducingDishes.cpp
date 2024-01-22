class Solution {
public:
    /*
        Problem:
        A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.
        Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction 
        level i.e. time[i] * satisfaction[i]. Return the maximum sum of like-time coefficient that the chef can obtain after preparing some 
        amount of dishes. Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.


            Approach:
            1. sort the array, we want to complete our most satisfying dishes last
                to take up the most amount of like-time coefficient
            2. calculate the like-time coefficient starting at every index and record
                the most like-time coefficient found
 
    */
    int maxSatisfaction(vector<int>& satisfaction) {
        
       int n = satisfaction.size();
       sort(satisfaction.begin(), satisfaction.end());
       if(satisfaction[n - 1] <= 0) return 0;

       int res = INT_MIN;
       for(int i = 0 ; i < n; i++){
           int sum = 0;
           for(int j = i; j < n; j++) {
               sum += (satisfaction[j] * (j - i + 1));
           }
           res = max(res, sum);
       }
       return res;
        
    }
};
