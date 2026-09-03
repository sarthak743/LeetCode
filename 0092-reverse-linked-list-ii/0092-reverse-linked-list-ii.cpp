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

//get temp till (left)th position
//keep beforeleft js before temp
//reverse nodes from temp till it reach right
//at end node js next to beforeleft will point to temp
//beforeleft point to prev

//3 edge case
//1. when both r same return as it is
//2. when right is last node well no need to handle separately code works properly
//3. when left is start node keep beforeleft at head and likewise update links

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next)
            return head;

        //when both r equal
        //return as it is
        if(left == right)
            return head;
        
        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* front = head;
        ListNode* beforeLeft = nullptr;     //node js before left to update the links

        int cnt = 1;
        while(cnt != left){
            cnt++;
            if(!beforeLeft)
                beforeLeft = head;
            else
                beforeLeft = beforeLeft->next;
            temp = temp->next;
        }

        //edge case
        if(cnt == 1)
            beforeLeft = head;

        while(cnt <= right){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
            cnt++;
        }

        //edge case 
        if(left == 1){
            beforeLeft->next = temp;
            return prev;
        }

        beforeLeft->next->next = temp;
        beforeLeft->next = prev;

        return head;        
    }
};