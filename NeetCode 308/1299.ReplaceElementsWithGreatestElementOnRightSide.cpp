class Solution {
public:
/*

    Problem
    
    Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.
    After doing so, return the array.
    
    Approach: 

    - declare result vector
    - declare a maxElement = -1 (the last element will always be -1)
    - iterate backwards through the array starting at the last element
        - add the maxElement to the result vector
        - if the maxElement is less less than arr[i]
            - set the maxElement = arr[i]
            //this way the max element is always the greatest element to the right of smaller indexes
        
    - since we iterated backwards, the result array is in reversed order
    
    -return a reversed version of the result array
*/
    vector<int> replaceElements(vector<int>& arr) {
        
        vector<int>res;
        int maxElement = -1;

        for(int i = arr.size() - 1; i >= 0; i--) {
            res.emplace_back(maxElement); //pushing the greatest element on the array
            maxElement = max(maxElement, arr[i]);//updating maxElement to be the greatest element
        }
        reverse(res.begin(), res.end());

        return res;

    }
};
