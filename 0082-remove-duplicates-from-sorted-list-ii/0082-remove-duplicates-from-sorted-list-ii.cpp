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

//make dummy node before head it will help returning result
//store prev pointer inside dummy
//if head and head->next hv same value (has duplicates)
//move head till it has that same value
//make prev point to head->next
//if theres no duplicate move prev 
//move head 

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;

        //will help returning the new list
        ListNode* dummy = new ListNode(-1, head);
        ListNode* prev = dummy;

        while(head){
            if(head->next && (head->val == head->next->val)){
                //move head till it got that duplicate value node
                while(head->next && (head->val == head->next->val))
                    head = head->next;

                //make prev point to next of head
                prev->next = head->next;
            }                

            else
                //if theres no duplicate move prev
                prev = prev->next;

            head = head->next;            
        }

        return dummy->next;
    }
};