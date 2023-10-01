class Solution {
public:

/*
    Problem:
       Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
       
    Approach:
        1. We will be solving this problem with dynammic programming
        2. We must compute the total number of nodes for n nodes, notice how the number of unique trees 
            for a tree with 0 or 1 total nodes is just 1, this will be our base case for our dynammic 
            programming algorithm
        3. In our algorithm, we will be calculating the number of unqiue binary trees there are for 
            EACH specific root node value. We will do this by keeping a running sum (currTrees) of the 
            number of unique binary trees for each root value
        4. For each root value notice that we can compute the # of left child nodes and # of right child
            nodes. Also notice how we know that value of dp[0] and dp[1] (1). This means that for every
            combination of children nodes for a current root value, we can calculate the total amount of
            unique subtrees it will have simply adding dp[left] * dp[right] to currTrees at every root value
        5. Then, at the end of traversing a single root, simply add currTrees to dp[current root value],
            and return the last value in the dp array
*/
    int numTrees(int n) {
       
        vector<int> trees(n + 1, n);

        // base cases
        trees[0] = 1;
        trees[1] = 1;

        
        // perform dynamic programming algorithmn to compute # of unique BSTs
        for(int root = 2; root < n + 1; root++) {
            int currTrees = 0;
            for(int val = 1; val <= root; val++) {
                int left = val - 1; // number of nodes to the left of the current root
                int right = root - val; // number of nodes to the right of the current root
                currTrees += (trees[left] * trees[right]);

            }
            trees[root] = currTrees;
        }

        return trees[trees.size() - 1];

    }
};
