/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution {
public:

/*
    Problem:
      Given the head of a linked list, remove the nth node from the end of the list and return its head.

    Approach:
        1. We will have two nodes that traverse through the list (node1 and node2)
        2. At first we will only traverse node1 n times, essentially delaying the traverse of node 2
        3. After doing this if we traverse both node1 and node2 until node1 does not have a next pointer,
            then our node2 will be exactly 1 node before the node that we are supposed to remove, so from 
            here we can just reassign node2's next pointer
        4.
*/
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        //only 1 node, return null
        if(head && !head->next){
            return nullptr;
        }

        //set up our 2 nodes
        ListNode* curr = head;
        ListNode* delayed = head;
        
        
        //delay delayed by n nodes
        while(n > 0) {
            curr = curr->next;
            n--;
        }

        //edge case, removing the first node
        if (curr == nullptr)
            return head->next;


        //traverse until curr does not have a next pointer
        while(curr && curr->next) {
            curr = curr->next;
            delayed = delayed->next;  
        }

        //reassign delayed's next pointer
        delayed->next = delayed->next->next;
        return head;

        
    }
};
