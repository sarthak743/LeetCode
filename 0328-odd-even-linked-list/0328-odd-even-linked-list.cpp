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

//BRUTE FORCE
//append odd values then even values in array
//iterate array and reassign the values with array values

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
            
        vector<int> arr;

        //append odd places nodes
        ListNode* temp = head;
        while(temp && temp->next){
            arr.push_back(temp->val);
            temp = temp->next->next;
        }

        //for last node if its remaining
        if(temp)
            arr.push_back(temp->val);

        //append even places nodes
        temp = head->next;
        while(temp && temp->next){
            arr.push_back(temp->val);
            temp = temp->next->next;
        }

        //for last node if its remaining
        if(temp)
            arr.push_back(temp->val);

        //final iteration
        temp = head;
        for(int i = 0; i < arr.size(); i++){
            temp->val = arr[i];
            temp = temp->next;
        }

        return head;
    }
};