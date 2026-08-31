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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        //for two and three nodes
        if(!head->next->next || !head->next->next->next)
            return {-1, -1};
        
        //making separate array and working on it
        vector<int> arr;
        ListNode* temp = head;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        //array for critical nodes
        vector<int> cric(arr.size(), 0);
        for(int i = 1; i < arr.size() - 1; i++){
            if(arr[i] > arr[i+1] && arr[i] > arr[i-1])
                cric[i]++;
            if(arr[i] < arr[i+1] && arr[i] < arr[i-1])
                cric[i]++;
        }

        int mini = -1, maxi = -1;

        //finding first and last critical
        int l = 0;                  //stores pos of first critical
        int r = cric.size() - 1;    //stores pos of last critical   
        while(l < cric.size()){
            if(cric[l] == 1)
                break;
            l++;
        }

        while(r >= 0){
            if(cric[r] == 1)
                break;
            r--;
        }

        //update only if we find
        //distinct criticals
        if(l < r){
            mini = cric.size();
            maxi = r - l;

            //put r ahead of l
            //if r hit critical get distance 
            //update that distance in mini
            //put l in r
            r = l + 1;
            while(r < cric.size()){
                if(cric[r] == 1){
                    mini = min(mini, r - l);
                    l = r;
                }
                r++;
            }
        }
            

        return {mini, maxi};        
    }
};