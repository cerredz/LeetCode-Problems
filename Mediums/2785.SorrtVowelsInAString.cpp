class Solution {
public:
    /*
      Problem:
        Given a 0-indexed string s, permute s to get a new string t such that:
        All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, then t[i] = s[i].
        The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels,
        then t[i] must not have a higher ASCII value than t[j]. Return the resulting string. The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase. 
        Consonants comprise all letters that are not vowels.

*/
    // helper function to check if a character is a vowel
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string sortVowels(string s) {
        // min heap to sort characters
        priority_queue<int, vector<int>, greater<int>> heap;
        unordered_set<int> vowel_indexes;

        // put all vowels into the min heap, and all indexes into the set
        int n = s.length();
        for(int i = 0; i < n; i++) {
            char letter = s[i];
            if(isVowel(letter)) {
                vowel_indexes.insert(i);
                heap.push(letter);
            }
        }

        // build the string using the heap, given string, and the set
        string res = "";
        for(int i = 0; i < n; i++) {
            char letter = s[i];
            if(isVowel(letter)) {
                res += heap.top();
                heap.pop();
            } else {
                res += letter;
            }

        }
        return res;

    }
};
