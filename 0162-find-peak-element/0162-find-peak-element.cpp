class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //edge case
        if(nums.size() == 1) return 0;

        //binary search from 1 to second last element
        int low = 1, high = nums.size() - 2;
        bool found = false;

        while(low <= high){
            int mid = (low + high) / 2;

            if(nums[mid - 1] < nums[mid] && nums[mid + 1] < nums[mid]){
                found = true;
                return mid;
            }

            if(nums[mid - 1] > nums[mid]) high = mid - 1;
            else low = mid + 1;
        }

        //for peaks at extreme point
        if(!found){
            if(nums[0] > nums[1]) return 0;
            if(nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;
        }

        return -1;
    }
};