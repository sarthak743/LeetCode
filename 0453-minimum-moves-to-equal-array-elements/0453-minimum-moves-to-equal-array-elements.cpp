//used idea from comments

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res = 0, mini = *min_element(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++)
            res += (nums[i] - mini);

        return res;
    }
};