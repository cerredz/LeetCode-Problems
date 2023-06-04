class Solution {
public:

/*
     Problem:
        We are given an array asteroids of integers representing asteroids in a row.
        For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). 
        Each asteroid moves at the same speed.Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode.
        If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
----------------------------------------------------------------------------------------------
    Approach:
        1. We must use a stack for this problem in order to backtrack to multiple
            previous asteroids

        2. We will iterate over the asteroids and seperate the problem into two cases:
            - the asteroid will cause a collision
            - the asteroid will not cause a collision

        3. The only way the asteroid will cause a collision is if the asteroid to the left
            of it is positive and the current astroid is negative, otherwise there is no
            collision and we can add the current astroid to the stack
        
        4. If there is a collision we must check three things:
            - if the collision causes an explosion between both
            - if the current astroid is the "bigger" one and causes the previous one to
                explode
            - if the previous astroid is the "bigger" one and causes the cuurrent one to
                explode

        5. After handling these cases, our stack will be the result in reverse order, 
            so return a reversed version of the stack in the form of a vector
----------------------------------------------------------------------------------------------
*/
    vector<int> asteroidCollision(vector<int>& asteroids) {

        //declare stack
        stack<int> st;

        //implement algorithm for Asteroid Collision
        for(int i = 0; i < asteroids.size(); i++) {

            //case 1: there is a collision
            while(!st.empty() && asteroids[i] < 0 && st.top() > 0) {
                
                //asteroids are the same, explode both
                if(st.top() + asteroids[i] == 0) {
                    st.pop();
                    asteroids[i] = 0; //setting asteroids[i] = 0 allows us to break from the while loop 
                //current astroid is "bigger" than previous astroid, explode previous
                } else if (st.top() + asteroids[i] < 0) {
                    st.pop();
                //previous atroid is "bigger than previous astroid", do nothing to the stack
                } else {
                    asteroids[i] = 0;
                }
            }
            
            //if asteroids[i] == 0 this means that a collision occured and we dont want to add the current asteroid to the stack, we can do this since a constraint is asteroids[i] != 0
            if(asteroids[i] != 0) {
                //case 2: there is no collision (if control reaches here)
                st.push(asteroids[i]);
            }
        }
    
        //reverse the stack in order to get the correct order of asteroids
        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;

    }
};
