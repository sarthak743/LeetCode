//same as BOOK ALLOCATION

class Solution {
public:
    //helper function
    //this will tell for a given "a" max allowed is possible or not
    bool isPossible(int a, vector<int>& arr, int b){
        int k = 0;
        int cnt = 0;

        for(int i = 0; i < arr.size(); i++){
            cnt += arr[i];
            if(cnt > a){
                k++;
                cnt = arr[i];
            }
        }

        //since at end cnt has non zero value
        //thus we will increment k by 1
        k++;     

        //if number of splits is lesser than equal to given k then its possible for this "a"
        return k <= b;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());       //low will have largest element
        int high = accumulate(nums.begin(), nums.end(), 0);     //high will have sum of array

        //used binary search to optimize
        while(low <= high){
            int mid = (low + high) / 2;

            if(isPossible(mid, nums, k))    high = mid - 1;
            else low = mid + 1;
        }

        //asnwer will be at low 
        return low;
    }
};