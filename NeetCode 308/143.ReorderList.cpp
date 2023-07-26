class Solution {
public:

/*
    Problem:
      You are given the head of a singly linked-list. The list can be represented as: L0 → L1 → … → Ln - 1 → L Reorder the list to be on the following form:
      L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → … You may not modify the values in the list's nodes. Only nodes themselves may be changed.


    Approach:
        1. One way that we can complete this problem is to reverse the second half of the list, and then merge
            the two halves of the list into one in the correct order
*/
    void reorderList(ListNode* head) {
        
        if(!head){
            return;
        }

        //need a slow and fast pointer to reverse the second half of head
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //now time to actually reverse the second half of the original ListNode
        ListNode* prev = nullptr;

        while(slow) {

            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        //prev is start of the second half of the list, head is start of the first half of the list

        //merge the two halfs of head into one ListNode in the correct order
        while(head && prev) {
            
            //point first half to second half
            ListNode* temp = head->next;
            head->next = prev;
            head = temp;

            //point second half to first half
            temp = prev->next;
            prev->next = head;
            prev = temp;

        } 


    }
};
