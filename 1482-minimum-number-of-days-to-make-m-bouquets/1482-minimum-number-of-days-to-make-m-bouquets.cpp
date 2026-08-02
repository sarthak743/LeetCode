//refer notes or video for explaination
//binary search used to optimize

class Solution {
public:
    bool isPossible(vector<int>& arr, int day, int m, int k){
        int cnt = 0;
        int bouq = 0;

        for(int i = 0; i < arr.size(); i++){
            if(arr[i] <= day){
                cnt++;
                if(cnt == k){
                    bouq++;
                    cnt = 0;
                }
            }

            else    cnt = 0;
        }

        return bouq >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        bool found = false;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while(low <= high){
            int mid = (low + high) / 2;

            if(isPossible(bloomDay, mid, m, k)){
                high = mid - 1;
                found = true;
            }

            else low = mid + 1;
        }

        if(!found) return -1;
        return low;
    }
};