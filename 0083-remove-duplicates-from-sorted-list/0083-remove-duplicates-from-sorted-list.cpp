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

//theres no need to delete those unwanted nodes always
//we can js move the next pointer to more further 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //when list has no or one node
        if(!head || head->next == nullptr)  return head;

        ListNode* temp = head;
        while(temp->next != nullptr){
            //move next pointer to next ka next node
            if(temp->next->val == temp->val)
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }
        return head;
    }
};