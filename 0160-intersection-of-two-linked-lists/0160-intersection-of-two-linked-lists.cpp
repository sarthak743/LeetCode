/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//get head of longer list ahead 
//so that both head have to 
//travel same distance till nullptr
//after that move both simultaneously by one 
//if they hit then true else false

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a = 0, b = 0, d = 0;
        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while(t1){
            a++;
            t1 = t1->next;
        }

        while(t2){
            b++;
            t2 = t2->next;
        }

        d = abs(a-b);
        if(a > b){
            while(d--)
                headA = headA->next;
        }

        else{
            while(d--)
                headB = headB->next;
        }
        
        while(headA && headB){
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return nullptr;
    }
};