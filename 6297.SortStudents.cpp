class Solution {
public:
  
  /*
  Problem: 
  There is a class with m students and n exams. You are given a 0-indexed m x n integer matrix score, where each row represents one student and score[i][j] denotes the score the ith student got in the jth exam. The matrix score contains distinct integers only.

You are also given an integer k. Sort the students (i.e., the rows of the matrix) by their scores in the kth (0-indexed) exam from the highest to the lowest.

Return the matrix after sorting it.


  */ 
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        
        vector<vector<int>> result;
        
        map<int, vector<int>, greater<int>> m;//we will sort map in descending order, and have the scores as the key
        
        for(int i = 0; i < score.size(); i++){
            m[score[i][k]] = score[i];
        }
        
        for(auto i : m) {
            result.emplace_back(i.second);//iterate through the map, and add the vector to the result vector of vector
        }
        
        return result;
        
        
    }
    
};
