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
      In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.
      For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
      The twin sum is defined as the sum of a node and its twin. Given the head of a linked list with even length, return the maximum twin sum of the linked list.

    Approach:   
        1. One way going about this problem is to reverse the second half of the list, this way we can compare the 
            nodes at the end of the list to the nodes at the front of the list
        2. We will reverse the second half of the list. At this point we will have a node starting at the first node
            of the original list and one node starting at the back of the list 
        3. We will traverse the node "inwards", and have a max variable to keep track of the greatest pairs of nodes
            seen. In order to traverse the nodes "inwards" just keep on pointing to the different node's node->next 
            val (since we reversed the second half)
        4. Return the greatest pair found
*/  
    int pairSum(ListNode* head) {
        
        //need slow and fast pointer to find second half of the list
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //reverse the list starting at slow
        ListNode* prev = nullptr;

        while(slow) {

            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        //prev is the start of our reversed second half list, now find the greatest pair
        int greatestPair = -1;
        while(prev && head) {
            greatestPair = max(head->val + prev->val, greatestPair);
            head = head->next;
            prev = prev->next;
        }

        return greatestPair;
        
    }
};
