/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:

/*
Problem:
  You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
*/
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        // implement level-order traversal
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                Node* curr = q.front();
                q.pop();
                // populate next pointer
                if(!q.empty() && i < n - 1) {
                    // check for i beacuse we dont want to connect last node on level to node on the next level
                    Node* next_node = q.front();
                    curr->next = next_node;
                }

                // push next level into the q
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }

        return root;
    }
};
