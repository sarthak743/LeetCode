class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int mini = nums[0], maxi = nums[n - 1];
        vector<int> mpp(maxi + 1, 0);       //array with maxi number of zeroes
        vector<int> result;         //empty array 

        for(int i = 0; i < n; i++)      mpp[nums[i]]++;

        for(int i = mini; i <= maxi; i++){
            if(!mpp[i]) result.push_back(i);        //append if element dont exist in nums
        }

        return result;
    }
};