/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

/*
    Problem:
      A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
      Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original
      node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the 
      same list state. None of the pointers in the new list should point to nodes in the original list.
      For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
      Return the head of the copied linked list. The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] 
      where: val: an integer representing Node.val random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
      Your code will only be given the head of the original linked list.
*/
    Node* copyRandomList(Node* head) {
        
        if(!head){
            return nullptr;
        }

        unordered_map<Node*, Node*> node_map;

        //iterate through head, and create new nodes to put into the map
        Node* curr = head;

        while(curr){
            node_map[curr] = new Node(curr->val);
            curr = curr->next;
        }

        //set the next and random pointers in the map
        curr = head;
        while(curr){

            node_map[curr]->next = node_map[curr->next];
            node_map[curr]->random = node_map[curr->random];

            //notice how we are doing node_map[curr->next], not curr->next, this makes sure that we are not pointing our next and random pointers to the original pointers in head, but rather the new nodes created in the map
            curr = curr->next;
        }

        //return the map[head]
        return node_map[head];

    }
};
