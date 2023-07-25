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
    ListNode* removeElements(ListNode* head, int val) {
        
        //while the leading value of head is = val, remove it
        while(head && head->val == val){
            head = head->next;
        }

        
        if(head == nullptr) {
            //all values in head were = val
            return nullptr;
        }

        //we will be returning head, so just have a current node that changes nodes
        ListNode* curr = head;

        //traverse through the nodes
        while(curr != nullptr && curr->next != nullptr) {

            if(curr->next->val == val) {
                //next node = val, reassign next to next.next
                curr->next = curr->next->next;
            } else {
                //only want to go to the next node if we did not reasign anything, or else we will end up skipping a node
                curr = curr->next;
            } 
        }
        return head;


    }
};
