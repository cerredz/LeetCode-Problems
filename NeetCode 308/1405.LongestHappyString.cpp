class Solution {
public:
/*
    Problem:
        A string s is called happy if it satisfies the following conditions:
        s only contains the letters 'a', 'b', and 'c'. 
        s does not contain any of "aaa", "bbb", or "ccc" as a substring.
        s contains at most a occurrences of the letter 'a'.
        s contains at most b occurrences of the letter 'b'.
        s contains at most c occurrences of the letter 'c'.
        Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. 
        If there is no such string, return the empty string "".
        A substring is a contiguous sequence of characters within a string.
        
    Approach:
        1. When inserting a character into our result string, our first choice would be to insert the most frequent 
            character (highest value between a, b, and c). Because of this we are going to sort these 
            numbers by using a max heap to always know the most frequent character at any given time
        2. When adding a character to our result string, if the previous two characters are not the same as our
            most frequent then we can simply just add the most frequent character to the end of our result string
        3. However, is the previous two characters are the SAME as our most frequent character, then there are two cases:
            - the max heap is empty: in this case we have reaches our longest possible string
            - the max heap is not empty: in this case just add the second most frequent character to the end of the 
                result string
        4. Whenever we add elements back into the max heap, make sure we decrement them by 1 before adding them back, 
            and only add them back into the max heap if their frequency is above 0
*/
    string longestDiverseString(int a, int b, int c) {
        
       
        // sort a, b, and c using a max heap
        priority_queue<pair<int, char>> max_heap;
        if(a > 0) {
            max_heap.push({a, 'a'});
        }

        if(b > 0) {
            max_heap.push({b, 'b'});
        }

        if(c > 0) {
            max_heap.push({c, 'c'});
        }
        

        // build the string using the frequency of each character
        string res = "";
        while(!max_heap.empty()) {

            pair<int, char> most_frequent = max_heap.top();
            max_heap.pop();

            // two cases to insert char into res
            int n = res.length();
            char most_frequent_char = most_frequent.second;
            if(n >= 2 && res[n - 1] == most_frequent_char && res[n - 2] == most_frequent_char) {
                // case 1: most frequent = previous 2 chars

                if(max_heap.empty()) {
                    return res;
                }

                pair<int, char> second_most_frequent = max_heap.top();
                max_heap.pop();

                res += second_most_frequent.second;
                second_most_frequent.first--;

                if(second_most_frequent.first > 0) {
                    max_heap.push(second_most_frequent);
                }
            } else {
                // case 2: no triple chars,  insert most frequent
                res += most_frequent_char;
                most_frequent.first--;
            }

            if(most_frequent.first > 0) {
                max_heap.push(most_frequent);
            }
        }

        return res;
    }
};
