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

//brute force
//put all values in stack
//then iterate list again 
//and replace the values with top()
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        while(temp){
            st.push(temp->val);
            temp = temp->next;
        }

        ListNode* temp1 = head;
        while(temp1){
            temp1->val = st.top();
            st.pop();
            temp1 = temp1->next;
        }

        return head;
    }
};