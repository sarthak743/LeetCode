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

//js like part 1
//reverse given lists add them
//return the reverse list

class Solution {
public: 
    ListNode* reverse(ListNode* head){
        if(!head || !head->next)
            return head;

        ListNode* prev = nullptr;
        ListNode* temp = head;
        ListNode* front = head->next;

        while(temp){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode* dummy = new ListNode(-1, nullptr);
        ListNode* temp = dummy;
        int sum = 0, carry = 0, to_add = 0;

        while(l1 && l2){
            sum = l1->val + l2->val;
            to_add = (sum + carry) % 10;
            carry = (sum + carry) / 10;

            ListNode* temp1 = new ListNode(to_add, nullptr);
            temp->next = temp1;
            temp = temp->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            to_add = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;

            ListNode* temp1 = new ListNode(to_add, nullptr);
            temp->next = temp1;
            temp = temp->next;

            l1 = l1->next;
        }

        while(l2){
            to_add = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;

            ListNode* temp1 = new ListNode(to_add, nullptr);
            temp->next = temp1;
            temp = temp->next;

            l2 = l2->next;
        }

        if(carry){
            ListNode* temp1 = new ListNode(carry, nullptr);
            temp->next = temp1;
            temp = temp->next;
        }

        return reverse(dummy->next);
    }
};