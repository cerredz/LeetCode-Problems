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
      Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, 
      and return the reversed list.

    Approach:
        1. We can solve this problem in 3 easy steps in 0(n) time complexity
        2. The first step is to set up two nodes, one that points at the left node in the list,
            and the other that points at the node right before the left node in the list. The
            reason for this previous node will become clear later on
        3. The second step is to reverse the list from left -> right
        4. The last step is to reassign the first and last node of the newly reversed list. Notice how
            since we have a prev node of left, we can simple just assign the prev->next to the 
            last node we reversed (which is why we had a prev node in the first place). Then, we want
            to reassign the last node in the newly reversed list to the node that came directly 
            after it before reversing it

*/
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(left == right){
            return head;
        }

        // step 1: set up a left and prev_left nodes
        ListNode* prev_left = new ListNode(0);
        ListNode* left_node = head;
        prev_left->next = head;

        for(int i = 0; i < left - 1; i++){
            left_node = left_node->next;
            prev_left = prev_left->next;
        }

        //left_nodes points at left, prev_left points at left - 1

        // step 2: reverse the list from left -> right
        ListNode* prev = nullptr;
        ListNode* curr = left_node;

        for(int i = left; i <= right; i++){

            ListNode* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        //prev = first node of reversed list, curr = next node that would have been reversed

        //step 3: reassign the pointers
        prev_left->next->next = curr;
        prev_left->next = prev;

        return left == 1 ? prev : head;//edge case, if left = 1, prev is our new head


    }
};
