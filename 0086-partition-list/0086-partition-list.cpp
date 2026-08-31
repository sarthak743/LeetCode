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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next)
            return head;

        ListNode* high = nullptr;       //track higher and equal to val
        ListNode* low = nullptr;        //track lower val
        ListNode* fhigh = nullptr;      //track first higher and equal
        ListNode* flow = nullptr;       //track first lower
        ListNode* temp = head;

        while(temp){
            if(temp->val < x){
                if(!low){
                    low = temp;
                    flow = low;
                }
                    
                else{
                    low->next = temp;
                    low = temp;
                }
            }

            else{
                if(!high){
                    high = temp;
                    fhigh = high;
                }

                else{
                    high->next = temp;
                    high = temp;
                }
            }

            temp = temp->next;
        }

        //when all nodes are higher
        if(!flow)
            return fhigh;

        //when all nodes are lower
        if(!fhigh)
            return flow;

        low->next = fhigh;
        high->next = nullptr;

        return flow;
    }
};