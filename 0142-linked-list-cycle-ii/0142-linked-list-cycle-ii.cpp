/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//BRUTE
//hashing
//key will be Node*
//iterate whole list if we find same node again they return it
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode* , int> mpp;
        ListNode* temp = head;

        while(temp){
            if(mpp[temp] == 1)
                return temp;
            mpp[temp]++;
            temp = temp->next;
        }

        return NULL;
    }
};