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
//RECURSIVE

//check video for better understanding

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //base case
        if(!head || !head->next)
            return head;

        ListNode* newhead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;

        return newhead;
    }
};