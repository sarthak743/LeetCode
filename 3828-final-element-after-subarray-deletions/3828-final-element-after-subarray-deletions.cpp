//to alice win the game (maximizing final state)
//she will remove subarray with length n - 1
//keeping the largest one behind
//which would be max of either of extremists

class Solution {
public:
    int finalElement(vector<int>& nums) {
        return max(nums[0], nums[nums.size() - 1]);
    }
};