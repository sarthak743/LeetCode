/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//first iterate both till they meet each other
//put slow at head
//after wards move both by 1
//return the slow where they meet again
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow){
                //move slow to starting point
                //which is at head
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }          

                return slow;      
            }
        } 
            
        return NULL;
    }
};