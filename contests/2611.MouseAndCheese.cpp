class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        
        //used to keep track of cheese that mice 1 has eaten
        vector<bool> eaten (reward1.size(), false);
        
       
        priority_queue<pair<int, int>> pq;
        int res = 0;
        
        //calculate the biggest differences between mouse 1 and mouse 2 in decreasing order by storing them in a max heap
        for(int i = 0; i < reward1.size(); i++){
            pq.push({reward1[i] - reward2[i], i});//remember to store index to keep track of indexes eaten already
        }
        
        //account for all cheese that mice 1 has eaten
        while(k > 0){
            //add reward1 value to res
            res += reward1[pq.top().second];
            //set index to eaten
            eaten[pq.top().second] = true;
            //get the next biggest difference
            pq.pop();
            
            k--;
        }
        
        //mouse 2 can eat unlimited cheese, add the indexes not just eaten by mouse 1 to res
        for(int i = 0; i < reward2.size(); i++){
            
            if(!eaten[i]){
                res += reward2[i];
            }
        }
        
        return res;
        
        
        

        
        
        
        
        
    }
};
