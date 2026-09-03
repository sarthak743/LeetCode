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

//get kth node
//keep pointer to memorize last of prev group
//reverse from temp to kthnode
//update links likewise
//stop if last group has less than k nodes

//keep next node after kthnode
//disconnect kthnode from rest list
//reverse that group 
//afterwards reconnect the links

class Solution {
public:
    //its alr if u dont return any node here
    void reverse(ListNode* head){
        if(!head || !head->next)
            return;

        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* front = temp->next;

        while(temp){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
    }

    ListNode* getKThNode(ListNode* temp, int k){
        //number of steps to move would ne k - 1
        k--;        
        while(temp && k > 0){
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = nullptr;

        while(temp){
            ListNode* kThNode = getKThNode(temp, k);
            //for last group 
            //if it has less than k nodes
            if(!kThNode){
                if(prevLast)
                    prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kThNode->next;
            kThNode->next = nullptr;
            reverse(temp);

            //new head
            if(temp == head)
                head = kThNode;
            else
                prevLast->next = kThNode;

            prevLast = temp;
            temp = nextNode;
        }

        return head;
    }
};