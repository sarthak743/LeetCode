class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> v;
        for(int i=0; i<2*n; i++)
        {
            if(i<n)
            {
                v.push_back(nums[i]);
            }
            else
            {
                v.push_back(nums[i-n]);
            }
        }        
        return v;
    }
};