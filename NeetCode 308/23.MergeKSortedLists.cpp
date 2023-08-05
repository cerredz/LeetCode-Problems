class Solution {
public:

/*
    Approach:   
        1. We will be using a priority queue in the form of a min heap in order to solve this problem
        2. We will iterate through all of the nodes in all of the listnodes in list. When we are 
            iterating we will put the listNodes into the priority queue. Since the priority queue
            is a min heap this means that the listnodes will be stores in ascending order (sorted)
        3. Since the prioirity queue is sorted, after adding all of the nodes to it we can iterate
            through the priority queue and build a completely new listnode until the priority queue
            is empty. This new listnode will be both a combination of all nodes in list and in sorted
            order
*/
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        //change max heap to min heap
        struct minHeap {
            bool operator()(const ListNode* a, const ListNode* b) {
                return a->val > b->val;
            }
        };

        //declare min heap
        priority_queue<ListNode*, vector<ListNode*>, minHeap> pq;

        //store the listNodes into the min heap
        for(int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                pq.push(lists[i]);
            }
        }

        //build a new listNode
        ListNode* res = new ListNode(0);
        ListNode* curr = res;

        //iterate though the min heap
        while(!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();

            curr->next = smallest;
            curr = curr->next;

            if (smallest->next) {
                //makes sure we are adding all of the nodes into the min heap
                pq.push(smallest->next);
            }
        }

        return res->next;
    }
};
