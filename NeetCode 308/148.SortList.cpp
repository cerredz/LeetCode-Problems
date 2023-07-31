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
      Given the head of a linked list, return the list after sorting it in ascending order.

    Approach:
        1. One way that we can solve this problem in 0(n log n)is by utilizing a min heap that take 
            in an int value and a listNode
        2. In order to sort the list simply, we can just traverse through it and in every iteration
            we add the value of the current listNode, and a new listNode with the listNode's value 
            to the min heap. This way when we are done traversing through the original ListNode
            it is configured in a way that is already in ascending order when iterating through the 
            min heap
        3. After done traversing through the listNode, we will build a new list from the ground up.
            If we just iterate through the min heap, create new listnode and connect them all, then 
            we will have a sorted list in the end since our min heap stores the values in sorted
            order
        4. Return the new list created
*/
    ListNode* sortList(ListNode* head) {
        
        struct Compare {
            bool operator()(const pair<int, ListNode*>& a, const pair<int, ListNode*>& b) {
                // Use greater-than for minHeap (ascending order)
                return a.first > b.first;
            }
        };

        //initialize a min heap
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, Compare> minHeap;

        //store the nodes into the min heap
        while(head) {
            minHeap.push({head->val, new ListNode(head->val)});
            head = head->next;
        }

        //build a new list from the ground up
        ListNode* res = new ListNode(0);
        ListNode* curr = res;

        //iterate through the min heap
        while(!minHeap.empty()){

            //connect the new nodes
            curr->next = minHeap.top().second;
            minHeap.pop();
            curr = curr->next;
        }

        //return new list
        return res->next;


    }
};
