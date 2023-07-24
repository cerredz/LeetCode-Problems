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
    Given the head of a singly linked list, return true if it is a  palindrome or false otherwise
*/
    bool isPalindrome(ListNode* head) {
        
        //save the original ListNode
        ListNode* original = head;

        //reverse the given ListNode, after we reverse it we will check if it is the same as the original
        ListNode* prev = nullptr;

        while(head != nullptr) {
            //when reversing, we have to make copy of head, so prev and original do not point to same ListNode
            ListNode* temp = new ListNode(head->val);
            temp->next = prev;
            prev = temp;
            head = head->next;
        }
        
        //reversed listnode starts at prev, compare it to the original
        while(original && prev) {
            
            if(original->val != prev->val){
                return false;
            }

            original = original->next;
            prev = prev->next;
            
        }

        return true;

    }
};
