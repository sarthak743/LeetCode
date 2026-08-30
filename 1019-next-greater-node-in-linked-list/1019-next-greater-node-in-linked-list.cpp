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

//double nested loop
//for every element search rest list
//if larger value found break inner loop and append in vector
//return result vector

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> result;
        int res = 0;

        ListNode* temp = head;
        while (temp) {
            ListNode* temp1 = temp->next;
            res = 0;

            while (temp1) {
                if (temp1->val > temp->val) {
                    res = temp1->val;
                    break;
                }

                temp1 = temp1->next;
            }

            result.push_back(res);
            temp = temp->next;
        }

        return result;
    }
};