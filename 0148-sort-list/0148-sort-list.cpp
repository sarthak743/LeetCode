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
//MERGE SORT
//refer video

class Solution {
public:
    //to find middle of list
    ListNode* middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* dummy = new ListNode(-1, nullptr);
        ListNode* temp = dummy;

        while(list1 && list2){
            if(list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        if(list1)
            temp->next = list1;
        else
            temp->next = list2;

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode* mid = middle(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);        
    }
};