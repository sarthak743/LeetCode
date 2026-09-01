/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//BRUTE
//get hash map keeping node as key
//iterate B and check map at each iteration
//return that node B if find

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> mpp;
        while(headA){
            mpp[headA]++;
            headA = headA->next;
        }

        while(headB){
            if(mpp[headB] == 1)
                return headB;
            headB = headB->next;
        }

        return NULL; 
    }
};