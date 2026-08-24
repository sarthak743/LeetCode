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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        //new list
        ListNode* dummy = new ListNode(-1, nullptr);
        ListNode* temp = dummy;

        //append lower value in dummy
        while(temp1 && temp2){
            if(temp1->val <= temp2->val){
                //new node 
                temp->next = new ListNode(temp1->val, nullptr);
                temp1 = temp1->next;
            }
                
            else{
                temp->next = new ListNode(temp2->val, nullptr);
                temp2 = temp2->next;
            }          

            temp = temp->next;      
        }

        //append remaining values 
        //when one gets exhausted
        while(temp1){
            temp->next = new ListNode(temp1->val, nullptr);
            temp1 = temp1->next;
            temp = temp->next;
        }

        while(temp2){
            temp->next = new ListNode(temp2->val, nullptr);
            temp2 = temp2->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};