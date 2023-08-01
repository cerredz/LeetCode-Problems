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
      Given the head of a linked list, rotate the list to the right by k places.
    Approach:
        1. Notice how if we rotate the list k times, the last k nodes will end up in the front of the 
            list. We will use this information in our solution
        2. In order to find what the last k nodes even are in the list we need to get the size of the
            list. After getting the size of the list, make sure that k is within the range of the 
            size of the list (remainder modulo)
        3. From this point, since we know the size, we can then traverse to the last k nodes. Once we
            traverse to the last k nodes we want to break the connection of the last k nodes and 
            the first size - k nodes and switch their order in the new list that we will be making
        4. After preforming step 3, return the new list
            



*/  
    ListNode* rotateRight(ListNode* head, int k) {
        
        //edge cases
        if(!head || k == 0){
            return head;
        }

        //get the length of the list
        ListNode* fast = head;
        int size = 1;
        while(fast->next) {
            fast = fast->next;
            size++;
        }


        //make sure that k is the kth node in the list
        k %= size;
        if(k == 0){
            return head;
        }

        //get the kth node from the end of the list
        ListNode* new_tail = head;
        
        for(int i = 1; i < size - k; i++) {
            new_tail = new_tail->next;
        }

        //we now have the kth node from the end of the list, swap the last k nodes with the beginning size - k nodes

        ListNode* new_head = new_tail->next; //last k nodes
        fast->next = head; //first size-k nodes + last k nodes
        new_tail->next = nullptr;//break connection of last k nodes (they are already at the front)

        return new_head;

    }
};
