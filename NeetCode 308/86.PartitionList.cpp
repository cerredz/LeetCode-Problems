class Solution {
public:

/*

    Problem:
      Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
      You should preserve the original relative order of the nodes in each of the two partitions.

    Approach:
        1. We need to somehow split the list into two groups, where one group is all greater than 
            or equal to x and another group is less than x.
        2. We will start this process by partitiong the list from the FIRST value we encounter that 
            is GREATER THAN or equal to x. We dont want to parition to exactly x because a listNode
            with a value of x is not gaurenteed to be in the list
        3. Once reaching a listNode with a value greater than or equal to x, we wil continue traversing
            through the listNode. If we find a value than is less than x we must do two things:
                - link the previous node to the next node (break the connection to the node that 
                    is less than x)
                - swap this node to the node prior to where we partitioned (must keep relative order)
        4. In order to achieve correct swapping, when we are trying to find our partition node, 
            we can also have a prev node that stays 1 node back from the partition node. This way
            we can easily swap nodes from the right half of the list to the left half

*/  
    ListNode* partition(ListNode* head, int x) {

        //declare partitiona and previous nodes
        ListNode* partition = head;
        ListNode* prev = nullptr;


        //find first node that is greater than or equal to x
        while (partition && partition->val < x) {
            prev = partition;
            partition = partition->next;
        }

        if (!partition) {
            // x value is either greater than or equal to all values in the list,
            // in this case return the original list
            return head;
        }


        //swap nodes with vals less than x on the right side to the left side of the list
        while (partition && partition->next) {

            if (partition->next->val < x) {
                //node that needs to be swapped found
                
                //break link of node with val < x
                ListNode* temp = new ListNode(partition->next->val);
                ListNode* temp_next = partition->next->next;
                partition->next = temp_next;


                //move the node to 1 index before the partition 
                if (!prev) {
                    //first element was greater than x, prev is null
                    temp->next = head;
                    head = temp;
                    prev = head;
                } else {
                    temp->next = prev->next;
                    prev->next = temp;
                }
            }
            //correctly traverse partition and prev
             else {
                partition = partition->next;
            }
            
            while (prev && prev->next && prev->next->val < x) {
                prev = prev->next;
            }
        }

        return head;
    }
};
