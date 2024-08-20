class Solution {
public:
/*
    problem:
      You are given two string arrays positive_feedback and negative_feedback, containing the words denoting positive and negative feedback, respectively. Note that no word is both positive and negative.
      Initially every student has 0 points. Each positive word in a feedback report increases the points of a student by 3, whereas each negative word decreases the points by 1.
      You are given n feedback reports, represented by a 0-indexed string array report and a 0-indexed integer array student_id, where student_id[i] represents the ID of the student who 
      has received the feedback report report[i]. The ID of each student is unique. Given an integer k, return the top k students after ranking them in non-increasing order by their points. In case more
      than one student has the same points, the one with the lower ID ranks higher.
*/
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        
        // first store all the positive and negative feedback words into two differnet sets for constant time lookup
        unordered_set<string> positive_words;
        unordered_set<string> negative_words;

        for(const string& s : positive_feedback) positive_words.insert(s);
        for(const string& s : negative_feedback) negative_words.insert(s);

        // go through each report, and track the corresponding student's score, inserting it into a min heap primarily
        // sorted based on points, then secondarily sorted on student_id

        int n = report.size();
        // configure heap accordingly
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
                    function<bool(const pair<int, int>&, const pair<int, int>&)>> 
                    heap([](const pair<int, int>& a, const pair<int, int>& b) {
                        if (a.first == b.first) {
                            return a.second > b.second;
                        }
                        return a.first < b.first;
                    });
        
        for(int i = 0; i < n; i++) {
            int score = 0;
            // get words in the report
            vector<string> words = getWords(report[i]);
            // using words, track the score, then insert it into the heap
            for(int i = 0; i < words.size(); i++) {
                if(positive_words.count(words[i]) > 0) score += 3;
                if(negative_words.count(words[i]) > 0) score -= 1;
            }
            
            heap.push({score, student_id[i]});
        }

        // add the k top elements of the heap into the res vector
        vector<int> res;
        while(k > 0) {
            int student_id = heap.top().second;
            heap.pop();
            res.push_back(student_id);
            k--;

        }
        return res;
    }

    vector<string> getWords(string str)
    {
        string word = "";
        vector<string> words;
        for (auto x : str) {
            if (x == ' '){
                words.push_back(word);
                word = "";
            }else {
                word = word + x;
            }
        }
        words.push_back(word);
        return words; 
    }
};
