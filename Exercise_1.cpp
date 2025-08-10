// Time Complexity : O(nlogk) where n is the number of elements in the array and k is the kth largest element we want to find.
 // Space Complexity : O(k) for max heap to store the k largest elements.
 // Space Complexity : O(1) if we use a min heap to store the k smallest elements.
 // Were you able to solve it on Leetcode : Yes
 // Any problem you faced while coding this : No

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // Min Heap approach
        // std::priority_queue<int, vector<int>, greater<int>> minHeap;
    
        // for (const int i: nums){
        //     minHeap.push(i);
        //     if(minHeap.size() > k){
        //         minHeap.pop();
        //     }
        // }

        // return minHeap.top();

        //Max Heap approach
        std::priority_queue<int> maxHeap;
        
        // Push all elements into the max heap so that the largest element is at the top
        for (const int i: nums){
            maxHeap.push(i);
        }

        // Pop the top k-1 elements to get to the kth largest element
        // The kth largest element will be at the top of the max heap after popping k-1 elements
        for(int i=0; i<k-1; i++){
            maxHeap.pop();
        }

        return maxHeap.top();

    }
};