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
      Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes 
      themselves may be changed.)

    Approach:
        1. If we want to keep the links between the ALL nodes, we are going to have to start from the
            previous node when swapping adjacent pairs. For example, in example 1 if u start at node 1
            and swap it with 2 that is fine. But when you get to node 3 and try to swap it with 4
            the link between 2 and 3 will be broken
        2. To solve this problem We will create an entirely differnt listNode, and build it up by
            using head. We will have a current listNode used for traversing head, and every iteration
            we will build up a listNode with swapped pairs(swapper). So if curr is 1->2, swapped will 
            be 2->1.
        3. After creating swapped, we will add it onto the end of our newly created listNode, and 
            traverse curr to the next adjacent pair until there are no adjacent pairs left. 
            
*/
    ListNode* swapPairs(ListNode* head) {

        //edge case, less than 2 nodes in head
        if(!head || !head->next){
            return head;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        ListNode* curr = head;

        //while there is still an adjacent pair
        while(curr && curr->next) {
            //build the swapped pair
            ListNode* first = new ListNode(curr->next->val);
            first->next = new ListNode(curr->val);

            //add it onto our new list
            prev->next = first;

            //traverse to next adjacent pair
            curr = curr->next->next;
            prev = prev->next->next;
        }

        //odd lengthed list, add last node onto new list
        if(curr && !curr->next) {
            prev->next = new ListNode(curr->val);
        }

        return dummy->next;
    }
};
