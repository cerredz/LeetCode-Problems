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
    Given the head of a linked list head, in which each node contains an integer value.
    Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.
    Return the linked list after insertion. The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

*/
    // helper function to get greatest common divisor between two numbers
    int getGCD(const int a, const int b) {

        int gcd = min(a, b);
        while(gcd > 0) {
            if(a % gcd == 0 && b % gcd == 0) {
                break;
            }
            gcd--;
        }
        return gcd;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        

        if(!head->next) return head;
        ListNode* curr = head;

        while(curr && curr->next) {
            // insert node in between curr and curr's next pointer
            ListNode* temp = curr->next;
            curr->next = new ListNode(gcd(curr->val, temp->val));
            curr->next->next = temp;

            curr = temp; // traverse curr 2 nodes at a time
        }

        return head;
    }
};
