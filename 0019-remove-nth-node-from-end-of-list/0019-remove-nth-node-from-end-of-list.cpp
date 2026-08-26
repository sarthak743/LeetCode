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
//move fast n times
//keep slow at head and move both tgt 
//till fast reaches end
//update the link and return 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next)
            return nullptr;

        ListNode* fast = head;
        while(n--)
            fast = fast->next;

        //for n equals size of list
        if(!fast)
            return head->next;

        //with this we get slow to
        //before the nth node from end
        ListNode* slow = head;
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return head;
    }
};