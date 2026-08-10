//approach same as AGGRESSIVE COWS
//first sort array
//minimum diff would be 0 (we cant say how low it can be so we take it as 0)
//maximum diff would be difference of first and last element
//get helper function to check if its possible to take a basket with k candies

//TC - O(N * log(maxi - mini))

class Solution {
public:
    bool isPossible(vector<int>& arr, int k, int minDiff){
        int a = minDiff;
        int count = 1;
        int last = arr[0];

        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - last >= a){
                last = arr[i];
                count++;
            }
        }

        return count >= k;
    }

    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());

        int low = 0;
        int high = price[price.size() - 1] - price[0];

        while(low <= high){
            int mid = (low + high) / 2;

            if(isPossible(price, k, mid))   low = mid + 1;
            else high = mid - 1;
        }

        return high;
    }
};