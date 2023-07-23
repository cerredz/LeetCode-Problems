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
      Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL. Initially, all next pointers are set to NULL.


    Approach:
        1. This is a very straightforward problem, and we will be utilizing level order traversal
        2. By using level order traversal, it is very easy to see that the last node's next pointer will be set to null
            in each level. However, if the node is not the last node in the level, simple set it's next pionter
            to the front of the queue.
        3. Repeat step 2 for every level
*/
    Node* connect(Node* root) {
        

        //edge case
        if(root == nullptr) {
            return nullptr;
        }

        
        Node* head = root;
        //need queue for level order traversal
        queue<Node*> q;
        q.push(head);

        //perform level order traversal
        while(!q.empty()) {
            
            
            int n = q.size();

            for(int i = 0; i < n; i++) {

                Node* top = q.front();
                q.pop();

                if (i < n - 1)
                    //node is not the last in the level
                    top->next = q.front();
                else
                    //last node in the level
                    top->next = nullptr;

                //push next level onto q
                if(top->left != nullptr) {
                    q.push(top->left);
                }

                if(top->right != nullptr) {
                    q.push(top->right);
                }

            }

            
        }

        return head;
    }
};
