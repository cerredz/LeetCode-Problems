class Solution {
public:
    /*
      You are given a positive integer array grades which represents the grades of students in a university. 
      You would like to enter all these students into a competition in ordered non-empty groups, such that the ordering meets the following conditions:
      The sum of the grades of students in the ith group is less than the sum of the grades of students in the (i + 1)th group, for all groups (except the last).
      The total number of students in the ith group is less than the total number of students in the (i + 1)th group, for all groups (except the last).
      Return the maximum number of groups that can be formed.


    */
    int maximumGroups(vector<int>& grades) {
        
        // sort in order to gaurentee that sum of group k <= k + 1
        int n = grades.size();
        sort(grades.begin(), grades.end());
        int groups = 1;
        int prev_group_size = 1, prev_group_sum = grades[0];
        int curr_group_size = 0, curr_group_sum = 0;

        // simulate creating the groups 
        for(int i = 1; i < n; i++) {
            curr_group_size++;
            curr_group_sum += grades[i];

            // use previous group size and sum to determine when to create another group
            if(curr_group_size > prev_group_size && curr_group_sum > prev_group_sum){
                groups++;
                prev_group_size = curr_group_size;
                prev_group_sum = curr_group_sum;
                curr_group_size = 0;
                curr_group_sum = 0;
            }
        }

        return groups;
    }
};
