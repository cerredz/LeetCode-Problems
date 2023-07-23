class Solution {
public:

/*
    Problem:

      You are given an array of strings products and a string searchWord.
    Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. 
    If there are more than three products with a common prefix return the three lexicographically minimums products.
    Return a list of lists of the suggested products after each character of searchWord is typed.

    Approach:
        1. Notice how the problem wants use to return "three lexicographically minimums products",  this is an 
        indication that we should use binary search for the optimal solution, and that is exactly what we are going to 
        do
        2. The problem wants us to return lexicographically string from the products vector, so this tells us that we 
        are going to sort the products vector, and utilize binary search on the products vector
        3. For the actual solution, first we simply just want to find the lower bound of all the possible search words 
        and see if we can add 3 strings with the same prefix to the result. 
        - For example: 
            - if the searchWord is "mouse", the first step is to find the lower bound of "m" in products, 
            remember products is sorted, using binary search. So we are finding the first word that starts with the 
            letter "m" in products
            - then we want to check if up to 3 words, starting from the lower bound, also start with "m" and if 
                so we add these words to a vector, and then whether or not we get all 3 we add this vector to our
                final 2d vector
            - we will repeat the above steps for the prefixes "mo", "mou", "mous", and finally "mouse"
        4. After we iterate through all possible search words, our 2d vector will have arrays of all the suggested
            products with a maximum length of 3 for each array

*/
    //helper function to search for suggested products, given a search word
    vector<string> search(vector<string>& products, string searchWord) {

        
        int left = 0, right = products.size() - 1, n = searchWord.length();
        vector<string> res;

        auto it = lower_bound(products.begin(), products.end(), searchWord); //finds the first occurence of searchWord in products using binary search

        //check for three lexicographically minimums products, starting at the lower bound
        for(; it != products.end(); it++) {

            if(it->substr(0,n) == searchWord && res.size() - 3) {
                //prefix matches and under 3 products found
                res.emplace_back(*it);
            } else {
                break;
            }
        }

        return res;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        

        //sort the products in alphabetical order, so we can perform binary search
        sort(products.begin(), products.end());

        //declare variables
        vector<vector<string>> res;
        string modified_search_word = "";

        //iterate through each possible search word
        for(char c : searchWord) {
            modified_search_word += c;
            //call helper function to search for suggested products
            res.emplace_back(search(products, modified_search_word));
        }
        return res;
    }
};
