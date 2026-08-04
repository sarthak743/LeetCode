//better approach
//TC - O(NlogN + (maxi - mini + 1))
//SC - O(maxi - mini - 1)   --> taken by result vector

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int mini = nums[0], maxi = nums[nums.size() - 1];
        vector<int> result;

        int j = 0;
        for(int i = mini; i <= maxi; i++){
            if(i != nums[j])    result.push_back(i);
            else    j++;
        }

        return result;
    }
};