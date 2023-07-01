class Solution {
public:

/*

    Problem:

        You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] 
        is the type of fruit the ith tree produces.You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow: 
        You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
        Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must
        fit in one of your baskets.
        Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
        Given the integer array fruits, return the maximum number of fruits you can pick.
---------------------------------------------------------------------------------------------
    Approach:
        1. We will be using a sliding window approach that utilizes a hashMap and a left 
            pointer starting at 0
        2. Our hashmap will keep track of the counts of all the different types of fruit, 
            this way we will be able to keep track of the total number of distinct fruits
            (incase it is every over 2)
        3. Start at the leftmost index, increment the count of the current fruit in our
            hashmap, then we must check if the hashmap is greater than size 2 since we can 
            only have two baskets of fruit
        4. If there is more than two fruits then we must slide our window in to the left
            until we have only two types of fruit. So while the map is greater than size 2, 
            we will decrement the map[left pointer] by 1, then increment left
        5. Notice that if there is no while loop, or after we exit the while loop, our left
            pointer and current index in the for loop will be a valid range of fruits 
            gathered with up to two baskets, so we can compare this range with our maximum
            range found so far.
        6. Return the maximum range founc
----------------------------------------------------------------------------------------------
*/
    int totalFruit(vector<int>& fruits) {
        
        //declare variables
        int left = 0, numBaskets = 0;
        unordered_map<int,int> distinctFruits;
    

        //implement sliding window algorithm
        for(int i = 0; i < fruits.size(); i++) {

            //keep count of fruits
            distinctFruits[fruits[i]]++;
            
            //slide window left if more than 2 fruits found
            while(distinctFruits.size() > 2) {

                distinctFruits[fruits[left]]--;
                if(distinctFruits[fruits[left]] == 0) {
                    distinctFruits.erase(fruits[left]);
                }
                left++;
            }

            //compare current range with max range found
            numBaskets = max(numBaskets, i - left + 1);

        }

        return numBaskets;



        
    }
};
