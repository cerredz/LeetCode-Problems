class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        
        int res = 0, length = 0, numZeros = 0;
        
        
        for(int i = 0; i < s.length(); i++) {
            
            length = 0;
            numZeros = 0;
            
            //once we encounter a zero we will start to look for a balanced string
            if(s[i] == '0') {
                
                int j = i;
                //count number of zeros
                while(j < s.length() && s[j] == '0'){
                    j++;
                    length++;
                    numZeros++;
                }
                
                //count number of 1s
                while(j < s.length() && s[j] == '1' && numZeros > 0){
                    numZeros--;
                    j++;
                    length++;
                }
                //need if check in case we have more zeros then 1's
                if(numZeros == 0){
                    //update only if balanced string's length is greater then the maximum one so far
                    res = max(res, length);
                }
                
                
            }
        }
            
        
        return res;
    }
};
