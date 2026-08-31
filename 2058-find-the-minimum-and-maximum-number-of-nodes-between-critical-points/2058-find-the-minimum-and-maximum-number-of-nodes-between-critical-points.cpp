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

//done with no extra space

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;

        int mini = INT_MAX, maxi = -1;

        int pos = 1;
        int first = -1, last = -1;
        while(curr && curr->next){
            bool cric = false;
            cric = ((curr->val > prev->val && curr->val > curr->next->val) || 
                    (curr->val < prev->val && curr->val < curr->next->val));

            if(cric && first == -1){
                first = pos;
                last = pos;
            }
                                
            
            if(cric && pos != first){                
                mini = min(mini, pos - last);
                last = pos;
            }

            pos++;
            prev = curr;
            curr = curr->next;
        }

        maxi = last - first;

        if(first == last){
            mini = -1;
            maxi = -1;
        }           

        return {mini, maxi};
    }
};