class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int, int> mpp;
        vector<int> res;

        for(int i=0; i<nums.size(); i++)
            for(int j=0; j<nums[i].size(); j++)
                mpp[nums[i][j]]++;

        for(auto i : mpp)
            if(i.second == nums.size())
                res.push_back(i.first);

        return res;
    }
};