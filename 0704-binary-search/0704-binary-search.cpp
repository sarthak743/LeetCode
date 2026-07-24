class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums[0] == target) return 0;
        
        int low = 0, high = nums.size() - 1;
        
        while(low <= high){
            int mid = (low + high) / 2;

            if(nums[mid] == target)     return mid;
            if(nums[mid] > target)  high = mid - 1;
            else    low = mid + 1;
        } 

        return -1;
    }
};