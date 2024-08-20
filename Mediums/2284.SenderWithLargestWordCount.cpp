class Solution {
public:

/*
    Problem:
      You have a chat log of n messages. You are given two string arrays messages and senders where messages[i] is a message sent by senders[i].
      A message is list of words that are separated by a single space with no leading or trailing spaces. The word count of a sender is the total number of words sent by the sender.
      Note that a sender may send more than one message. Return the sender with the largest word count. If there is more than one sender with the largest word count, return the one with the 
      lexicographically largest name.
*/
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        
        // use a map to store the word counts of each sender
        unordered_map<string, int> map;
        int n = messages.size();
        int most_words_sent = 0;
        string res = "";

        for(int i = 0; i < n; i++) {
            string message = messages[i];
            string name = senders[i];
            int num_spaces = 0; 
            // calculate words in each message, then store it into the hashmap
            for(int j = 0; j < message.length(); j++) {
                if(message[j] == ' ') num_spaces++;
            }
            map[name] += (num_spaces + 1);

            // see if person has sent the most messages
            if(map[name] > most_words_sent || (map[name] == most_words_sent && name > res)) {
                most_words_sent = map[name];
                res = name;
            }
        }

        return res;
    }
};
