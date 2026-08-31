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

//make dummy nodes at beginning
//for both lower and higher val
//update the links acc to val of head
//at end update the final link
//this handles edge cases very well

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lowdummy = new ListNode(INT_MIN, nullptr);
        ListNode* highdummy = new ListNode(INT_MIN, nullptr);

        ListNode* low = lowdummy;
        ListNode* high = highdummy;

        while(head){
            if(head->val < x){
                low->next = head;
                low = head;
            }

            else{
                high->next = head;
                high = head;
            }

            head = head->next;
        }

        low->next = highdummy->next;
        high->next = nullptr;

        return lowdummy->next;
    }
};