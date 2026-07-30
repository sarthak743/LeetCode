class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //for single element in array
        if(nums.size() == 1) return nums[0];

        //checking first element
        if(nums[0] != nums[1])  return nums[0];     

        //checking last element
        if(nums[nums.size() - 1] != nums[nums.size() - 2])  return nums[nums.size() - 1];      

        int low = 1, high = nums.size() - 2;

        while(low <= high){
            int mid = (low + high) / 2;

            //check the neighbours if both are different then thats our result
            if(nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])    return nums[mid];

            //if mid is odd and element prev to it is equal to nums[mid] then eliminate left part
            //if mid is even and element next to it is equal to nums[mid] then eliminate left part
            if((mid % 2 == 1 && nums[mid - 1] == nums[mid]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1]))    low = mid + 1;
            else high = mid - 1;        //eliminate right part if above condition dont pass
        }

        return -1;
    }
};