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
      You are given the head of a linked list, and an integer k.
      Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed)/

    Approach:
        1. To start off this algorithn we need to first time the nth node from the end of the list. To do 
            this we will use two nodes, (denoted 'fast' and 'slow'). We will traverse fast until it is at the
            position of the kth node from the BEGINNING. Then we will traverse both nodes until fast does 
            not have a next node. After we do with the slow node will be in the position of the kth
            node from the END of the list
        2. Now we will take another node, (denoted beginning) and traverse it until it is at the position 
            of the kth node from the beginning of the list. At this point, we will swap the values of 
            beggining and slow as both of the nodes are in the correct position
*/
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* fast = head;
        ListNode* slow = head;

        //set up slow to be positioned in the kth node from the end of the list
        for(int i = 1; i < k; i++) {
            fast = fast->next;
        }

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        //slow node in the correct spot, not time to position another node at the kth node from the beginning
        ListNode* beginning = head;
        for(int i = 1; i < k; i++) {
            beginning = beginning->next;
        }

        //swap the two values of the nodes
        int temp = slow->val;
        slow->val = beginning->val;
        beginning->val = temp;

        return head;


    }
};
