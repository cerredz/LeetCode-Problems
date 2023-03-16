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
------------------------------------------------------------------------------------------------
    Approach:
        1. Iterate through the linked list until the last node in order to get the size of
            the linked list
        2. Iterate back until the size of the list - n, and have a current node and a previous
            node that you are keep track of
        3. Set the previous node's next pointer to the current node's next pointer
------------------------------------------------------------------------------------------------
    Psuedocode:
        - initialize a currentNode = head and a prevNode = nullptr, and a size varibale
            to keep track of the linked list's size

        - while the current node's next pointer is not null
            - set current node its next value
            - increment size by 1
        
        - set current node back to the start of the linked list

        - for each index up until (size - n):
            - set the prev node = current node
            - set the current node = current node.next

        - set the prevNode.next = currentNode.next

        - return the linked list given
------------------------------------------------------------------------------------------------
*/
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        //current Node
        ListNode* currentNode = head;

        //previous Node
        ListNode* prevNode = nullptr;

        //get the size of the linked list
        int size = 1;
        while(currentNode->next != nullptr) {
            currentNode = currentNode->next;
            size++;
        }
        //reset currentNode back to the start
        currentNode = head;

        //traverse prevNode untill the node behind the one you want to remove
        int iterations = size - n;
        while(iterations > 0) {
            prevNode = currentNode;
            currentNode = currentNode->next;
            iterations--;
        }

        //edge case. This means that the algorithm is telling us to remove first node.
        if(prevNode == nullptr) {
            return head->next;
        //prev the previous node's next pointer to 2 nodes in front of it
        }else {
            prevNode->next = currentNode->next;
        }
    
        return head;

  
        
    }
};
