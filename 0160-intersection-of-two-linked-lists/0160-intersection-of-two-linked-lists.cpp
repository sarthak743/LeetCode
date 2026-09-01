/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//iterate both
//when t1 reach nullptr put t1 to start of other list
//same for other
//theyll hit if intersection exists
//also both travel same distance at the end (sum of len of both list)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)    
            return nullptr;

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        //loop terminates when both r equal
        //1. when theres intersection
        //2. when both reach nullptr (after tail) of respective lists
        while(t1 != t2){     
            t1 = t1->next;
            t2 = t2->next;

            //immediately check 
            //else it will go infinite loop
            if(t1 == t2)
                return t1;       

            //for first time t1 reaches null
            //send it back to headB
            if(!t1)
                t1 = headB;
            if(!t2)
                t2 = headA;            
        }

        //returns intersection node if exists
        //if no t1 reaches nullptr which is good to return it as it is
        return t1;
    }
};