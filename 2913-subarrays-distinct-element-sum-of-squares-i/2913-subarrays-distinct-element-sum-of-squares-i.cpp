class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int res = 0;
        
        for(int i=0; i<nums.size(); i++){
            unordered_map<int, int> mpp;
            for(int j=i; j<nums.size(); j++){
                mpp[nums[j]]++;
                res += mpp.size() * mpp.size();
            }
        }

        return res;
    }
};