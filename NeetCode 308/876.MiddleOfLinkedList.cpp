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
    Given the head of a singly linked list, return the middle node of the linked list.
    If there are two middle nodes, return the second middle node.
*/  
    ListNode* middleNode(ListNode* head) {
        
       ListNode* fast = head;
       ListNode* slow = head;

       //we will have a fast and slow node, the fast one will traverse 2 nodes ever iteration, and the slow node will traverse only 1

       while(fast && fast->next) {
           slow = slow->next;
           fast = fast->next->next;
       }

       return slow;

       
    }
};
