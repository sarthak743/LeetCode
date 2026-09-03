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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        ListNode* t0 = head;
        ListNode* t1 = head;
        while(t0){
            n++;
            t0 = t0->next;
        }

        //number of steps to move
        int f = k-1;      //front
        int b = n-k;  //behind
        t0 = head;

        while(f--)
            t0 = t0->next;

        while(b--)
            t1 = t1->next;

        swap(t0->val, t1->val);
        return head;
    }
};