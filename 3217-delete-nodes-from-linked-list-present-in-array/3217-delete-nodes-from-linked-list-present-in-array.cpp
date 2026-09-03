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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++)
            mpp[nums[i]]++;

        while(mpp[head->val])
            head = head->next;

        ListNode* temp = head;
        while(temp && temp->next){
            if(mpp[temp->next->val])
                temp->next = temp->next->next;
            else
                temp = temp->next;      //move temp when next node dont exist in nums
        }

        return head;    
    }
};