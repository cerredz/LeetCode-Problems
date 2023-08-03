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
      Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.
      The steps of the insertion sort algorithm: Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
      At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
      It repeats until no input elements remain. The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains
      only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.


    Approach:
        1. In order to solve this problem we will have two pointers that point at different nodes
        2. The first pointer will serve as an iterator, simply just going through the list  
            and be used to check values. The second pointer we be used to check where a number 
            should be placed if it needs to be swapped in the list
        3. Start at the leftmost index, use our first pointer to check if the next value is greater
            than the value at the first pointer, if it is this is where we use our second pointer.
            Traverse the second pointer, starting at the leftmost index, until we find a bigger
            number than the number that needs to be swapped. Then, insert the swapped number 
            into the list, and update the first pointer's next pointers for the lower value.
        4.  If there is a swap we dont need to change our first pointer, but if no swap happens
            then simply just move our first pointer to the next node in the list. As far as our 
            second pointer, we only need this when there is a swap necessary, and it will 
            always start at the first node in the list
        5. Continue step 3-4 until we traverse all the nodes in the list
*/
    ListNode* insertionSortList(ListNode* head) {
        
        //dummy node, not one of the pointers
        ListNode* prev = new ListNode(0);
        prev->next = head;

        
        //traverse through the list, head = first pointer
        while(head && head->next){

            //check if there is a swap needed
            if(head->next->val < head->val){
                //swap needed, declare our second pointer
                ListNode* insertion = prev;

                //check where the swapped value needs to be inserted in the list
                while(insertion->next->val < head->next->val) {
                    insertion = insertion->next;
                }

                //insert swapped value into list, then rearranged pointers
                ListNode* temp = insertion->next;
                insertion->next = new ListNode(head->next->val);
                insertion->next->next= temp;

                head->next = head->next->next;
            } else {
                //no swap needed, move onto next node
                head = head->next;
            }
            
        }

        return prev->next;
        

    }
};
