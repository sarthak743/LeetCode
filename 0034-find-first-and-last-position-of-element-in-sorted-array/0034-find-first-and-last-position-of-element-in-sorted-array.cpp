//Binary Search
//answer to this question is {lower bound, upper bound - 1}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = nums.size(), ub = nums.size();

        //lower bound
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = (low + high) / 2;

            if(nums[mid] >= target){
                lb = mid;
                high = mid - 1;
            }
            else low = mid + 1;            
        } 

        //upper bound
        low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = (low + high) / 2;

            if(nums[mid] > target){
                ub = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        //if target dont occur in array then return -1
        if(lb == nums.size() || nums[lb] != target) return {-1, -1};
        return {lb, ub - 1};
    }
};