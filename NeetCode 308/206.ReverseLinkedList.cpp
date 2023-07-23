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
      Given the head of a singly linked list, reverse the list, and return the reversed list.
*/
    ListNode* reverseList(ListNode* head) {
        
        //need current and prev nodes
        ListNode* curr = head;
        ListNode* prev = nullptr;

        //iterate through all nodes
        while(curr != nullptr) {
            
            //obtain the next node before breaking the connection
            ListNode* temp = curr->next;
            //reverse the current's pointer
            curr->next = prev;

            //do the same thing on the next two nodes
            prev = curr;
            curr = temp;
        }
        
        //curr is nullptr, prev is last node in original order
        return prev;
    }
};
