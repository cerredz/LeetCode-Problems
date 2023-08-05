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
          Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
          k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, 
          should remain as it is. You may not alter the values in the list's nodes, only nodes themselves may be changed.

        Approach:
            1. In order to reverse the next k nodes, we need to make sure that there are k nodes left.
                That is exactly what we will do in every iteration in our while loop, by first 
                checking if there are k nodes left for us to reverse
            2. The next step we will take, if there are k nodes left, is to actually reverse the k
                nodes, and here are the steps we need to take to reverse the k next nodes in the list:
                    - have one node (curr) pointing at the first node in the pre-reversed list, save
                        a copy of this node into another node as well (prev_curr)
                    - have another node (prev) pointing to the node to the left of curr
                    - reverse the next k nodes, now all we have to do is reconnect the links
                    - curr is at the position of the start of the next k nodes, so assign prev_curr's 
                        next to curr
                    - reassign prev to the left node of curr again (prev_curr)

            3. At first glance I though that we would have to traverse curr and prev after reversing,
                but by performing step 2 repeatedy these two pointers will make their way through the 
                list automatically
    */
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        //declare pointers
        ListNode* prev_k = new ListNode(0);
        prev_k->next = head;

        ListNode* curr = head;
        ListNode* res = prev_k;

        while(curr) {

            //check if there are still k nodes in the list
            ListNode* nodes_left = curr;
            for(int i = 0; i < k; i++){
                if(!nodes_left){
                    return res->next;
                }
                nodes_left = nodes_left->next;
            }

            //enough nodes, reverse the next k nodes in the list
            ListNode* prev = nullptr;
            ListNode* prev_head = curr;
            for(int i = 0; i < k; i++) {
                ListNode* next = curr->next;
                curr->next = prev;

                prev = curr;
                curr = next;
            }
            
            //reconnect the broken links
            prev_head->next = curr;
            prev_k->next = prev;
            prev_k = prev_head;
        }

        return res->next;
    }
};
