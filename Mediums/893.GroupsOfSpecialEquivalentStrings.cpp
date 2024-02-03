class Solution {
public:
    /*
        Problem:
        You are given an array of strings of the same length words. In one move, you can swap any two even indexed characters or any two odd indexed characters of a string words[i].
        Two strings words[i] and words[j] are special-equivalent if after any number of moves, words[i] == words[j]. For example, words[i] = "zzxy" and words[j] = "xyzz" are special-equivalent 
        because we may make the moves "zzxy" -> "xzzy" -> "xyzz". A group of special-equivalent strings from words is a non-empty subset of words such that:
        Every pair of strings in the group are special equivalent, and The group is the largest size possible (i.e., there is not a string words[i] not in the group such that words[i]
        is special-equivalent to every string in the group). Return the number of groups of special-equivalent strings from words.

        Approach:
            1. We can use a combination of sorting and hashing to solvve this problem
            2. We need to seperare a strings even and odd indexes because we have to make
                sure that we dont compare an even index to an odd index
            3. After we make two string from a singular string, sort the 2 strings, and then
                concatenate them. Use this concatenation as a key in our hashMap, and increment it
            4. Repeat steps 1-3 for every word in words, and then return the size of the map
            
    */
    int numSpecialEquivGroups(vector<string>& words) {
        
        int n = words.size();
        unordered_map<string, int> map; 
        
        for(int i = 0; i < n; i++) {
            string even_letters;
            string odd_letters;

            // extract even / odd indices
            for(int j = 0; j < words[i].length(); j += 2) even_letters += words[i][j];
            for(int j = 1; j < words[i].length(); j += 2) odd_letters += words[i][j];

            // sort, concatenate, then hash
            sort(even_letters.begin(), even_letters.end());
            sort(odd_letters.begin(), odd_letters.end());
            string key = even_letters + odd_letters;
            cout << key << endl;
            map[key]++;

        }
        return map.size();
    }
};
