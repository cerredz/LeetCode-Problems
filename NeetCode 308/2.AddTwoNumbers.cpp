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
          You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single 
          digit. Add the two numbers and return the sum as a linked list. You may assume the two numbers do not contain any leading zero, except the number 0 itself.


        Approach:
            1. Notice that in the explanation of the solution they are reversing twice to get the output, 
                this tells us that we dont actually have to do any type of reversing to get the correct 
                solution
            2. In fact the solution is pretty straightforwards we just have to make sure to handle some edge
                cases. All we have to do is calculate the sum of two nodes at the same index. If this sum is 
                less than 10 we can add it to our res ListNode. Otherwise we add 1 to the next ListNode's val
            3. If one List is greater than the other list, simply just add the digit onto our res list. 
                However, this is where an edge case comes into play, remember when he added 1 to the next 
                listNode in step 2. Well this means that a value in the greater listNode could be 10. In this
                case, add 1 to the next listNode's value, and if there is no next listNode create a new 
                one with a value of 1
            4. Return res listNode after iterating through both l1 and l2
    */

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        ListNode* res = new ListNode(0);
        ListNode* curr = res;


        while(l1 && l2) {

            //calculate the sum of the current nodes value in each list
            int digit_sum = l1->val + l2->val;
            

            if(digit_sum >= 10) {

                //add sum % 10 to res
                int new_sum = digit_sum - 10;
                res->next = new ListNode(new_sum);

                //add 1 to the next node's val, make sure the next node is not null
                if(l1->next) {
                    l1->next->val += 1;
                } else if (l2->next) {
                    l2->next->val += 1;
                } else {
                    //both next nodes are null, create a new one
                    res = res->next;
                    l1->next = new ListNode(1);
                }

            } else {
                //sum is not greater than 10
                res->next = new ListNode(digit_sum);
            }

            //traverse the nodes
            res = res->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        //l1 is bigger than l2
        while(l1) {

            //edge case, l1->val is 10
            if(l1->val == 10) {
               
                res->next = new ListNode(0);

                //add 1 to the next node, only if it exists
                if(l1->next) {
                    l1->next->val += 1;
                } else {
                    l1->next = new ListNode(1);
                }

            } else {
                res->next = new ListNode(l1->val);
            }
        
            res = res->next;
            l1 = l1->next;
        }

        //l2 is bigger than l2, perform same tasks as above while loop, just on l2 and not l1
        while(l2) {
            
            if(l2->val == 10) {
                res->next = new ListNode(0);
                if(l2->next) {
                    l2->next->val += 1;
                } else {
                    l2->next = new ListNode(1);
                }
            } else {
                res->next = new ListNode(l2->val);
            }
            res = res->next;
            l2 = l2->next;
        }

        return curr->next;

        
    }
};
