//almost missing number is
//number appearing in only subarray
//if k = n
//then we return largest value
//coz they might appear more than once in same subarray 
//but that number appears only in one subarray which whole array (for k == n)

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> mpp(51, 0);
        int result = -1;

        // mapping
        for (int i = 0; i < nums.size(); i++)
            mpp[nums[i]]++;

        if (k == nums.size()) {
            result = -1;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > result)
                    result = nums[i];
            }
        }

        else if (k == 1) {
            result = -1;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > result && mpp[nums[i]] == 1)
                    result = nums[i];
            }
        }

        else {
            if (mpp[nums[0]] == 1 && mpp[nums[nums.size() - 1]] == 1)
                result = max(nums[0], nums[nums.size() - 1]);

            else if (mpp[nums[0]] == 1 && mpp[nums[nums.size() - 1]] > 1)
                result = nums[0];

            else if (mpp[nums[0]] > 1 && mpp[nums[nums.size() - 1]] == 1)
                result = nums[nums.size() - 1];
        }
        return result;
    }
};