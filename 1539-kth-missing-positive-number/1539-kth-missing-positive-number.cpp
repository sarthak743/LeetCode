//binary search
//refer notes or video for explaination
//TC - O(logN)

class Solution {
public:
    int no_of_missing_numbers(int a, vector<int>& arr){
        return arr[a] - a - 1;
    }

    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;

        while(low <= high){
            int mid = (low + high) / 2;

            if(no_of_missing_numbers(mid, arr) >= k)  high = mid - 1;
            else low = mid + 1;
        }

        if(high == -1) return k;        //edge case
        return arr[high] + k - no_of_missing_numbers(high, arr);
    }
};