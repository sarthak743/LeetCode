class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int prod = 1;
        int n = nums.size();
        int z_cnt = 0;
        vector<int> result;

        for(int i=0; i<n; i++)
        {
            if(nums[i] == 0)    z_cnt++;
            prod *= nums[i];
        }

        if(z_cnt == 1)
        {
            prod = 1;
            for(int i=0; i<n; i++)
            {
                if(nums[i] != 0)    prod *= nums[i];
            }

            for(int i=0; i<n; i++)
            {
                if(nums[i] == 0)    result.push_back(prod);
                else    result.push_back(0);
            }
        }
        
        else if(z_cnt > 1)
        {
            for(int i=0; i<n; i++)
            {
                result.push_back(0);
            }
        }

        else
        {
            for(int i=0; i<n; i++)
            {
                result.push_back(prod / nums[i]);
            }
        }        

        return result;
    }
};