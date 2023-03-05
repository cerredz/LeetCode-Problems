class Solution {
public:
    int passThePillow(int n, int time) {
        
        //used for switching directions
        bool end = false;
        //actual start is 1, but we start at 2 to not mess up bool logic
        int start = 2;
        time--;
        
        //while there is still time
        while(time > 0) {
            
            //if we reach the end, or the start, we must switch directions
            if(start == n) {
                end = true;
            } else if (start == 1) {
                end = false;
            }
            
            if(!end) {
                start++;
                time--;
            }else {
                time--;
                start--;
            }
        }
        
        //return the position we are in after time = 0
        return start;
    
        
        
    }
};
