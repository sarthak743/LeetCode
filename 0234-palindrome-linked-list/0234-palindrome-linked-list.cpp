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

//make string of the values
//then rev it and then if its palindromic
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string s = "";
        ListNode* temp = head;
        while(temp != nullptr){
            s += temp->val;
            temp = temp->next;
        }
        string dup = s;
        reverse(dup.begin(), dup.end());
        return s == dup;
    }
};