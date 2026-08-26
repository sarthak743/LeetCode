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

//find middle with slow and fast
//keep prev pointer which stays just behind slow
//once we find middle
//update the link of prev and return

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        //for no node and single node
        if(!head || !head->next)
            return nullptr;

        ListNode* prev = head;      //node to memorize before of slow pointer
        ListNode* slow = head->next;
        ListNode* fast = head->next->next;

        //find the middle
        while(fast && fast->next){
            slow = slow->next;
            prev = prev->next;
            fast = fast->next->next;
        }

        prev->next = prev->next->next;

        return head;
    }
};