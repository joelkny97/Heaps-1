// Time Complexity : O(nlogk) where n is the number of elements in the lists and k is the number of linked lists.
// Space Complexity : O(k) for the min heap to store the k smallest elements.
// Were you able to solve it on Leetcode : Yes
// Any problem you faced while coding this : No

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
class Compare {
public:
    // Custom comparator for the ListNode priority queue to create a min heap
    bool operator()(ListNode* a, ListNode* b){
        return (a->val > b->val) ;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Using a min heap to store the ListNode pointers
        // This will allow us to efficiently get the smallest element from the k lists
        std::priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        // Push the first element of each list into the min heap
        for(ListNode* i: lists){
            if(i!=nullptr){
                minHeap.push(i);
            }
        }

        // dummy node to handle edge cases and simplify the merging process
        // curr will be used to keep track of the last node in the merged list
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        // While there are elements in the min heap, we will keep merging
        while(!minHeap.empty()){
            // Get the smallest element from the min heap
            ListNode* min = minHeap.top();
            minHeap.pop();  
            
            // Add the smallest element to the merged list
            curr->next = min;

            // If the smallest element has a next node, push it into the min heap
            if (min->next != nullptr){
                minHeap.push(min->next);
            }
            // Move the curr pointer to the last node in the merged list
            curr = curr->next;
        }
        // Return the merged list starting from the first node after the dummy node
        return dummy->next;

        
    }
};