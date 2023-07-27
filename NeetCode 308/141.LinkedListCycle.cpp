/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

/*
    Problem:
      Given head, the head of a linked list, determine if the linked list has a cycle in it.There is a cycle in a linked list if there is some node in the list that can be reached 
      again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed 
      as a parameter. Return true if there is a cycle in the linked list. Otherwise, return false.


    Approach:
        1. We will have a fast node and a slow node, our fast node will traverse the 
            list 2 nodes at a time, while our slow node will traverse the list 1 node
            at a time
        2. If there is a cycle, both nodes will eventually meet, and if they do we 
            can return true
        3. If there is no cycle, our fast node will eventually be null, and if
            this is the case then we return false
*/
    bool hasCycle(ListNode *head) {
        
        //edge case
        if(!head){
            return false;
        }

        //declare slow and fast node
        ListNode* slow = head;
        ListNode* fast = head;

        //look for cycle until fast node is null
        while(fast && fast->next) {
            
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                //cycle found
                return true;
            }
        }

        //no cycle found since fast node is null
        return false;
    }
};
