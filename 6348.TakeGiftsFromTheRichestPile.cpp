
class Solution {
public:
  /*
   --------------------------------------------------------------------------------------------------------------------------------------------------------------------
   Problem:
      You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:
      Choose the pile with the maximum number of gifts.If there is more than one pile with the maximum number of gifts, choose any.
      Leave behind the floor of the square root of the number of gifts in the pile. Take the rest of the gifts.
      Return the number of gifts remaining after k seconds.
  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Approach:
      - while we still have seconds left we will be finding the largest number and replace the index with the square root of that number
      - after the number of seconds run out we will just calculate the sum of the vector
  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------
 

  */
    long long pickGifts(std::vector<int>& gifts, int k) {
        
        int currLargest = 0, currLargestIndex = 0;//keep track of largest number in vector, and index of largest number
        long long res = 0;//final answer
        while(k > 0) {//while we still have seconds left
            
            currLargest = 0;//reset largest and largest index
            currLargestIndex = 0;
            
            for(int i = 0; i < gifts.size(); i++) {//find largest and largest index
                if (gifts[i] > currLargest) {
                    currLargest = gifts[i];
                    currLargestIndex = i;
                }
            }
            gifts[currLargestIndex] = sqrt(currLargest);//replace largest number with its square root
            k--;
        }
        
        for(int i : gifts) {//calculate sum
            res += i;
        }
        return res;
        
    }
};
