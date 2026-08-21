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

 //stoled the solution from Youtube
 //Neso Academy
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(!head || head->next == nullptr) return head;  

        ListNode* prev = NULL;
        ListNode* link = NULL;
        while(head != NULL)
        {
            link = head->next;
            head->next = prev;
            prev = head;
            head = link; 
        }      
        head = prev;
        return head;
    }
};