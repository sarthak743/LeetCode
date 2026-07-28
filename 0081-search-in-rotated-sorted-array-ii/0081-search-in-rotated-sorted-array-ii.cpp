//similar to part 1 with just one tweak
//edge case occurs when elements at all positions (low, mid, high) comes to be equal
//at that case we cant really say which side is sorted 
//solution we trim array by 1 from both side when this happens


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while(low <= high){
            int mid = (low + high) / 2;

            if(nums[mid] == target) return true;

            //edge case condition
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }

            if(nums[mid] >= nums[low]){
                if(nums[low] <= target && target < nums[mid])   high = mid - 1;
                else low = mid + 1;
            }

            else{
               if(nums[mid] < target && target <= nums[high])    low = mid + 1;
               else high = mid - 1; 
            }
        } 

        return false;
    }
};