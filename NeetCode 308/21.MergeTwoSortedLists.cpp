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
      You are given the heads of two sorted linked lists list1 and list2. Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the
      first two lists. Return the head of the merged linked list.

*/
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        //create two nodes, one that we will be returning, and one that we will use to update the one that we are returning
        ListNode* curr = new ListNode();
        ListNode* dummy = curr;

        //we will be implementing the merge part of mergesort, just with ListNodes

        //iterate through both ListNodes
        while(list1 != nullptr && list2 != nullptr) {

            //set curr.next to the smaller number
            if(list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }

            curr = curr->next;
        }

        //if remaining nodes in any of the lists, just add the whole ListNode to the end of curr, at most 1 ListNode will have remaining nodes at this point, and they will all be bigger than the node values in curr
        if(list1) {
            curr->next = list1;
        } else if (list2) {
            curr->next = list2;
        }
        


        return dummy->next;


        

    }
};
