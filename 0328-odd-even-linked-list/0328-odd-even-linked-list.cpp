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

//OPTIMAL 
//link odd placed nodes tgt
//link even placed nodes tgt
//lastly link end of odd with start of even

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;
        
        //since odd follows even
        //we only put condition of even 
        while(even && even->next){
            //link odd with odd 
            odd->next = odd->next->next;
            //link even with even
            even->next = even->next->next;

            //move both pointers ahead
            odd = odd->next;
            even = even->next;
        }

        //last operation
        odd->next = evenHead;

        return head;
    }
};