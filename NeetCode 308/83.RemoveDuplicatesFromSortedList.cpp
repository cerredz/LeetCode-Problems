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
    Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
*/
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == nullptr){
            return nullptr;
        }

        //create 2 nodes, one will be directly in front of the other at all times
        ListNode* curr = head;
        ListNode* temp = curr->next;

        while(temp) {
            

            if(curr->val == temp->val) {
                //duplicate found, set next pointer of curr to node with different value
                while(temp && curr->val == temp->val) {
                    temp = temp->next;
                }
                curr->next = temp;
            } 

            //traverse the two nodes
            curr = curr->next;
            if(temp && temp->next) {
                //need if statement incase last element was a duplicate, in that case temp would be set to nullptr
                temp = temp->next;
            }
        
        }

        return head;
    }
};
