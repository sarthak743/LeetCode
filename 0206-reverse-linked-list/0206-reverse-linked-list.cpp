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
//ITERATIVE

//3 pointers

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;      //curr
        ListNode* prev = nullptr;   //prev
        ListNode* front = nullptr;  //front

        while(temp){
            front = temp->next;     //keep front ahead of curr
            temp->next = prev;      //make curr point to prev
            prev = temp;            //move prev ahead
            temp = front;           //move temp ahead too
        }

        return prev;        //new head will be at end which is prev
    }
};