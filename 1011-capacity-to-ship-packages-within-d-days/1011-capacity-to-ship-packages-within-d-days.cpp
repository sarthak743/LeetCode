//clean code
//submitted with helper function
//same approach as before

class Solution {
public:
    bool isPossible(vector<int>& arr, int maxDays, int maxAllowed){
        int days = 1;
        int allowed = 0;

        for(int i = 0; i < arr.size(); i++){
            allowed += arr[i];
            if(allowed > maxAllowed){
                allowed = arr[i];
                days++;
            }
        }

        return days <= maxDays;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high){
            int mid = (low + high) / 2;

            if(isPossible(weights, days, mid))  high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }
};