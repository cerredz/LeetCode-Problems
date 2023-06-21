class Solution {
public:
/*
    Problem:
      Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. 
      That is, no letter appears in a single substring more than once. Return the minimum number of substrings in such a partition.
      Note that each character should belong to exactly one substring in a partition.
-----------------------------------------------------------------------------------------------------------------
    Approach:
        1. We will use a set to keep track of all the unique characters in a partition.
        2. Starting at the leftmost index of s, we will check if the character is in the set, if it is not we 
            will add it to the set, if it is in the set this means that we have to create another partition
            of s. What we will do here is clear the set, increment the number of partitions seen so far,
            and add the current character back to the set.
        3. Repeat step 3 for every index of s
        4. Return the number of paritions we find
----------------------------------------------------------------------------------------------------------------
*/
    int partitionString(string s) {

        //declare variables
        unordered_set<char> set;

        //need to start at 1 to account for first partition
        int numPartitions = 1;

        //implement algorithmn for finding all partitions
        for(int i = 0; i < s.length(); i++) {

            //duplicate character, create a new partition
            if(set.count(s[i])) {
                set.clear();
                numPartitions++;
            }

            //insert current character in the set no matter what
            set.insert(s[i]);
        }

        //total number of partitions have been found
        return numPartitions;
    }
};
